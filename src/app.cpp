//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/os.hpp>
#include "portable-file-dialogs.h"

#include "core/element.h"
#include "core/scene_system.h"
#include "core/scene_node.h"
#include "core/bind_core_classes.h"
#include "core/io/file_system_io.h"
#include "core/resource.h"
#include "core/io/io_index.h"
#include "input/bind_input_classes.h"
#include "spatial/bind_spatial_classes.h"
#include "ui/bind_ui_classes.h"
#include "desktop/bind_desktop_classes.h"
#ifdef _WIN32 // hack fix for MSVC. TODO: this is dumb
//#include <hxluasimdjson.cpp>
//#include <simdjson.cpp>
#else
//#include <hxluasimdjson.h>
//#include <simdjson.h>
#endif
#include <sol/sol.hpp>
#include <cstdlib>
#include <string>
#include <array>
#include <memory>
#include <stdexcept>

using namespace sunaba;
using namespace sunaba::core;
using namespace sunaba::core::io;
using namespace godot;


void App::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start", "path"), &App::start);
}

void free_global_state(App* app) {
    //free(app->global_state);
}

App::App() {
}

App::~App() {
    global_state.collect_garbage();
    IoIndex::unbindIoManager(global_state);
    //UtilityFunctions::print("App destructor");
}

void App::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
}

void App::start( const String &path) {
    if (path == "") {
        return;
    }
    global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
        sol::lib::count, sol::lib::math, sol::lib::string,
        sol::lib::table, sol::lib::utf8, sol::lib::package, 
        sol::lib::os, sol::lib::io, sol::lib::debug );

        lua_State* L = global_state.lua_state();
// hack fix for PUC-Rio Lua
#ifdef USE_PUCRIO_LUA
        luaopen_bit(L);
#endif
    

    global_state["print"] = [this]( sol::variadic_args args ) {
        String msg;
        for ( const auto &arg : args )
        {
            if ( arg.is<std::string>() )
            {
                std::string str = arg.as<std::string>();
                msg += str.c_str();
            }
            else if (arg.is<sol::table>())
            {
                msg += "table";
            }
            else if (arg.is<Vector3>())
            {
                Vector3 vec = arg.as<Vector3>();
                msg += String(vec);
            }
            else if (arg.is<Vector2>())
            {
                Vector2 vec = arg.as<Vector2>();
                msg += String(vec);
            }
            else if (arg.is<float>())
            {
                float f = arg.as<float>();
                Variant v = f;
                msg += String(v);
            }
            else if (arg.is<bool>())
            {
                bool b = arg.as<bool>();
                Variant v = b;
                msg += String(v);
            }
            else if (arg.is<int>())
            {
                int i = arg.as<int>();
                Variant v = i;
                msg += String(v);
            }
            else if (arg.is<Vector4>())
            {
                Vector4 vec = arg.as<Vector4>();
                msg += String(vec);
            }
            else if (arg.is<Vector4i>())
            {
                Vector4i vec = arg.as<Vector4i>();
                msg += String(vec);
            }
            else if (arg.is<Vector2i>())
            {
                Vector2i vec = arg.as<Vector2i>();
                msg += String(vec);
            }
            else if (arg.is<Vector3i>())
            {
                Vector3i vec = arg.as<Vector3i>();
                msg += String(vec);
            }
        }
        godot::UtilityFunctions::print( msg );
    };

    //UtilityFunctions::print("Hello, World!");
    //sunaba::core::
    sunaba::input::bindInputClasses(global_state);
    sunaba::core::bindCoreClasses(global_state);
    sunaba::spatial::bindSpatialClasses(global_state);
    sunaba::ui::bindUIClasses(global_state);
    sunaba::desktop::bindDesktopClasses(global_state);

    auto* rootElement = new sunaba::core::Element(this);
    rootElement->isRootElement = true;
    global_state["rootElement"] = rootElement;
#ifdef _WIN32
    // Register hx-lua-simdjson module
    //global_state.require("hx_lua_simdjson", luaopen_hxsimdjson, false);
#endif
    ioManager = new IoManager();
    IoIndex::bindIoManger(global_state, ioManager);
    auto fsio = FileSystemIo::create(path.utf8().get_data(), "app://");
    //UtilityFunctions::print(fsio->basePath.c_str());
    ioManager->add(fsio);
    global_state.set("ioManager", ioManager);

    ////sunaba::core::bind_all_godot_classes( global_state );
    //sunaba::core::initialize_lua( global_state );

    global_state.set_function( "createScene", [this]() {
        return createScene();
    });

    //sol::error *e = nullptr;

    std::string script = ioManager->loadText("app://main.lua");
    //UtilityFunctions::print(script.c_str());
    //global_state.script(script);
    /*
    global_state.script(extract_luarocks_lua_paths());
    global_state.script(R"(
        print(package.cpath)
        --package.path = "/usr/local/lib/luarocks/rocks-5.1/?.lua;" .. package.path
        --package.cpath = "/usr/local/lib/luarocks/rocks-5.1/?.so;" .. package.cpath
    )");

    if (OS::get_singleton()->has_feature("editor")) {
        UtilityFunctions::print("Running in editor mode, skipping luarocks path setup.");
        if (OS::get_singleton()->get_name() == "macOS") {
            UtilityFunctions::print("macOS detected, setting up luarocks path.");
            
        }
    }
    */
    sol::protected_function_result result = global_state.safe_script(script, sol::script_pass_on_error);
    
    if ( !result.valid() ) {
        sol::error err = result;
        UtilityFunctions::print( String( "Error: " ) + err.what() );
        auto msgBox = pfd::message(
            "Error", err.what(), pfd::choice::ok, pfd::icon::error
        );
        msgBox.result();
    } else {
        //UtilityFunctions::print("Script executed successfully");
    }
}

void App::_process(double delta) {
    global_state.collect_garbage();
}

Scene* App::createScene() {
    auto sceneNode = memnew( SceneNode );
    auto scene = sceneNode->getScene();
    add_child(sceneNode);
    scene->viewport = get_viewport();
    return scene;
}