//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#ifdef USE_PORTABLE_FILE_DIALOGS
#include "portable-file-dialogs.h"
#endif

#include "core/element.h"
#include "core/scene_system.h"
#include "core/scene_node.h"
#include "core/bind_core_classes.h"
#include "core/io/file_system_io.h"
#include "core/io/zip_io.h"
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
#ifdef USE_LUASOCKET
#include <luasocket.h>
// Declare the symbol reference function
extern void sunaba_ensure_luasocket_symbols();

// Forward declaration for mime.core Lua module initializer
extern "C" {
    int luaopen_mime_core(lua_State *L);
}
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
    ClassDB::bind_method(D_METHOD("init_state", "sandboxed"), &App::initState);
    ClassDB::bind_method(D_METHOD("load_and_execute_sbx", "path"), &App::loadAndExecuteSbx);
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

int App::loadFileRequire(lua_State* L) {
    // This function is used to load a file and require it in Lua
    // It should return 1 if successful, 0 otherwise
    const char* filename = luaL_checkstring(L, 1);
    if (!filename || strlen(filename) == 0) {
        sol::stack::push(
	     L, "Error: filename is empty");
        return 0;
    }

    auto ioInterface = IoIndex::getIoManager(global_state);
    if (!ioInterface) {
        sol::stack::push(
	     L, "Error: IoManager not found");
        return 0;
    }

    if (!String(filename).ends_with(".lua")) {
        filename =  String(String(filename) + ".lua").utf8().get_data();
    }

    if (!ioInterface->fileExists(filename)) {
        sol::stack::push(
	     L, "Error: file does not exist: " + String(filename));
        return 0;
    }

    auto file = ioInterface->loadText(filename);

    if (file.empty()) {
        sol::stack::push(
         L, "Error: failed to load file: " + String(filename));
        return 0;
    }

    luaL_loadbuffer(L, file.c_str(), file.size(), filename);
    
    return 1; // return the result of the require call
}

void App::initState(bool sandboxed) {
    if (!sandboxed) {
        global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
            sol::lib::count, sol::lib::math, sol::lib::string,
            sol::lib::table, sol::lib::utf8, sol::lib::package, 
            sol::lib::os, sol::lib::io, sol::lib::debug );
        global_state["sandboxed"] = false;
    }
    else {
        global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
            sol::lib::count, sol::lib::math, sol::lib::string,
            sol::lib::table, sol::lib::utf8, sol::lib::package);
        global_state["sandboxed"] = true;
    }

    global_state.clear_package_loaders();
    global_state.add_package_loader(App::loadFileRequire);

        lua_State* L = global_state.lua_state();
// hack fix for PUC-Rio Lua
#ifdef USE_PUCRIO_LUA
        luaopen_bit(L);
#endif
    
    if (!sandboxed) {
#ifdef USE_LUASOCKET
        // Ensure luasocket symbols are linked
        sunaba_ensure_luasocket_symbols();
        lua_getglobal(L, "package");
        lua_getfield(L, -1, "preload");
    
        lua_pushcfunction(L, luaopen_socket_core);
        lua_setfield(L, -2, "socket.core");
    
        lua_pushcfunction(L, luaopen_mime_core);
        lua_setfield(L, -2, "mime.core");
    
        lua_pop(L, 2);
        //
#endif
    } 

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
    ioManager = new IoManager();
    IoIndex::bindIoManger(global_state, ioManager);
    global_state.set("ioManager", ioManager);

    ////sunaba::core::bind_all_godot_classes( global_state );
    //sunaba::core::initialize_lua( global_state );

    global_state.set_function( "createScene", [this]() {
        return createScene();
    });


    auto fsio = FileSystemIo::create(ProjectSettings::get_singleton()->globalize_path("res://corelib/").utf8().get_data(), "corelib://");
    //UtilityFunctions::print(fsio->basePath.c_str());
    ioManager->add(fsio);
    //sol::error *e = nullptr;
}

void App::loadAndExecuteSbx(const String &path) {
    if (path == "") {
        return;
    }
    if (!path.ends_with(".sbx")) {
        UtilityFunctions::print("Error: path must end with .sbx");
        return;
    }
    auto zipio = new ZipIo(path.utf8().get_data());
    zipio->pathUri = "temp://";
    ioManager->add(zipio);

    auto headerJsonStr = zipio->loadText("header.json");
    if (headerJsonStr.empty()) {
        UtilityFunctions::print("Error: header.json not found in the sbx file");
        return;
    }
    //UtilityFunctions::print("header.json: " + String(headerJsonStr.c_str()));
    auto headerJson = godot::Ref<JSON>(memnew(JSON));
    auto parseResult = headerJson->parse_string(headerJsonStr.c_str());
    Dictionary headerDict = parseResult;

    auto type = headerDict.get("type", "executable");
    if (type != "executable") {
        UtilityFunctions::print("Error: type must be executable");
        return;
    }

    auto luabinname = headerDict.get("luabin", "main.lua");
    zipio->pathUri = String(headerDict.get("rootUrl", "app://")).utf8().get_data();

    std::string luabinPath = String(String(zipio->pathUri.c_str()) + String(luabinname)).utf8().get_data();

    //UtilityFunctions::print("Loading Lua binary: " + String(luabinPath.c_str()));

    std::string script = ioManager->loadText(luabinPath);
    sol::protected_function_result result = global_state.safe_script(script, sol::script_pass_on_error);
    
    if ( !result.valid() ) {
        sol::error err = result;
        UtilityFunctions::print( String( "Error: " ) + err.what() );
#ifdef USE_PORTABLE_FILE_DIALOGS
        auto msgBox = pfd::message(
            "Error", err.what(), pfd::choice::ok, pfd::icon::error
        );
        msgBox.result();
#else
        OS::get_singleton()->alert(
            err.what(), "Error"
        );
#endif
        
    } else {
        //UtilityFunctions::print("Script executed successfully");
    }
}

void App::start( const String &path) {
    if (path == "") {
        return;
    }
    auto fsio = FileSystemIo::create(path.utf8().get_data(), "app://");
    //UtilityFunctions::print(fsio->basePath.c_str());
    ioManager->add(fsio);

    std::string script = ioManager->loadText("app://main.lua");
    sol::protected_function_result result = global_state.safe_script(script, sol::script_pass_on_error);
    
    if ( !result.valid() ) {
        sol::error err = result;
        UtilityFunctions::print( String( "Error: " ) + err.what() );
#ifdef USE_PORTABLE_FILE_DIALOGS
        auto msgBox = pfd::message(
            "Error", err.what(), pfd::choice::ok, pfd::icon::error
        );
        msgBox.result();
#else
        OS::get_singleton()->alert(
            err.what(), "Error"
        );
#endif
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