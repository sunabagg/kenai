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
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
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
#include "ui/global_theme.h"
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

#ifdef USE_LUASEC
extern "C" {
    extern int luaopen_ssl_core(lua_State *L);
    extern int luaopen_ssl_x509(lua_State *L);
}
#endif

#ifdef USE_LUV
extern "C" {
    extern int luaopen_luv(lua_State *L);
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
    ClassDB::bind_method(D_METHOD("start_mobdebug", "host", "port"), &App::startMobdebug);
    ClassDB::bind_method(D_METHOD("stop_mobdebug"), &App::stopMobdebug);
    ClassDB::bind_method(D_METHOD("set_theme", "theme"), &App::setTheme);
    ClassDB::bind_method(D_METHOD("set_args", "_args"), &App::setArgs);
    ClassDB::bind_method(D_METHOD("get_args"), &App::getArgs);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_STRING_ARRAY, "args"), "set_args", "get_args");
    ADD_SIGNAL(MethodInfo("on_exit"));
}

void App::setTheme(Ref<Theme> theme) {
    sunaba::ui::uiGlobals::setGlobalTheme(new sunaba::ui::Theme(theme.ptr()));
    global_state["theme"] = sunaba::ui::uiGlobals::getGlobalTheme();
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

    // Get the sol::state from the lua_State
    sol::state_view lua(L);
    
    auto ioInterface = IoIndex::getIoManager(lua);
    if (!ioInterface) {
        sol::stack::push(
	     L, "Error: IoManager not found");
        return 0;
    }

    //filename = ioInterface->getFilePathFromLuaRequirePath(filename).c_str();

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
#ifndef USE_PUCRIO_LUA
            global_state.open_libraries( sol::lib::ffi );
#endif
        global_state["sandboxed"] = false;
    }
    else {
        global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
            sol::lib::count, sol::lib::math, sol::lib::string,
            sol::lib::table, sol::lib::utf8, sol::lib::package);
        global_state["sandboxed"] = true;
    }

    auto execDir = OS::get_singleton()->get_executable_path().get_base_dir();
    if (OS::get_singleton()->get_name() == "macOS") {
        // On macOS, the executable path is usually in Contents/MacOS/ directory
        execDir = execDir.replace("/MacOS", "/Resources/").replace("\\MacOS", "\\Resources");
    }
    auto execFile = OS::get_singleton()->get_executable_path().get_file();
    auto shareDir = OS::get_singleton()->get_executable_path().replace("bin/" + execFile, "share/sunaba");
    if (DirAccess::dir_exists_absolute(shareDir)) {
        execDir = shareDir;
        global_state["shareDir"] = shareDir.utf8().get_data();
        global_state.script("package.path = package.path .. ';' .. shareDir .. '/?.lua'");
    }
    else {
        global_state["shareDir"] = sol::lua_nil;
    }
    
    global_state["execDir"] = execDir.utf8().get_data();
    global_state.script("package.path = package.path .. ';' .. execDir .. '/?.lua'");
    global_state.script("print(package.path)");

    //global_state.clear_package_loaders();
    global_state.add_package_loader(&App::loadFileRequire);

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
        lua_setfield(L, -2, "socket");
    
        lua_pushcfunction(L, luaopen_mime_core);
        lua_setfield(L, -2, "mime");
    
        lua_pop(L, 2);
        //
#endif

#ifdef USE_LUASEC
        lua_getglobal(L, "package");
        lua_getfield(L, -1, "preload");

        lua_pushcfunction(L, luaopen_ssl_core);
        lua_setfield(L, -2, "ssl.core");

        lua_pushcfunction(L, luaopen_ssl_x509);
        lua_setfield(L, -2, "ssl.x509");
        
        lua_pop(L, 2);
#endif

#ifdef USE_LUV
        lua_getglobal(L, "package");
        lua_getfield(L, -1, "preload");

        lua_pushcfunction(L, luaopen_luv);
        lua_setfield(L, -2, "luv");

        lua_pop(L, 2);
#endif
        
        // Initialize mobdebug support
        initMobdebug();
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

    global_state["exit"] = [this]() {
        this->emit_signal("on_exit");
    };

    //UtilityFunctions::print("Hello, World!");
    //sunaba::core::
    sunaba::input::bindInputClasses(global_state);
    sunaba::core::bindCoreClasses(global_state);
    sunaba::spatial::bindSpatialClasses(global_state);
    sunaba::ui::bindUIClasses(global_state);
    sunaba::desktop::bindDesktopClasses(global_state);
    if (!sandboxed) {
        bindRuntime(global_state);
    }

    auto* rootElement = new sunaba::core::Element(this);
    rootElement->isRootElement = true;
    global_state["rootElement"] = rootElement;
    ioManager = new IoManager();
    IoIndex::bindIoManger(global_state, ioManager);
    global_state.set("ioManager", ioManager);

    ////sunaba::core::bind_all_godot_classes( global_state );
    //sunaba::core::initialize_lua( global_state );

    auto fsio = FileSystemIo::create(ProjectSettings::get_singleton()->globalize_path("res://corelib/").utf8().get_data(), "corelib://");
    //UtilityFunctions::print(fsio->basePath.c_str());
    ioManager->add(fsio);
    //sol::error *e = nullptr;
}

void App::loadAndExecuteSbx(const String &path) {
    if (path == "") {
        return;
    }
    if (!godot::FileAccess::file_exists(path)) {
        UtilityFunctions::print("Error: file does not exist");
        get_tree()->quit();
        return;
    }
    auto zipio = new ZipIo(path.utf8().get_data());
    if (zipio->getErrorCode() != godot::Error::OK) {
        UtilityFunctions::print("Error: failed to open sbx file");
        get_tree()->quit();
        return;
    }
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

    //std::string luabinPath = String(String(zipio->pathUri.c_str()).replace("://", ".") + String(luabinname)).utf8().get_data();
    std::string luabinPath = String(String(zipio->pathUri.c_str()) + String(luabinname)).utf8().get_data();

    //UtilityFunctions::print("Loading Lua binary: " + String(luabinPath.c_str()));

    global_state["luaBinPath"] = luabinPath;
    
    // Auto-start mobdebug if environment variable is set
    auto debugEnv = std::getenv("SUNABA_DEBUG");
    if (debugEnv && std::string(debugEnv) == "1") {
        UtilityFunctions::print("Debug mode enabled, starting MobDebug...");
        auto hostEnv = std::getenv("MOBDEBUG_HOST");
        auto portEnv = std::getenv("MOBDEBUG_PORT");
        std::string host = hostEnv ? std::string(hostEnv) : "localhost";
        int port = portEnv ? std::atoi(portEnv) : 8172;
        startMobdebug(host.c_str(), port);
    }

    global_state["__args"] = args;
    
    sol::protected_function_result result = global_state.safe_script("require('" + luabinPath + "')", sol::script_pass_on_error);
    
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

    // Auto-start mobdebug if environment variable is set
    auto debugEnv = std::getenv("SUNABA_DEBUG");
    if (debugEnv && std::string(debugEnv) == "1") {
        UtilityFunctions::print("Debug mode enabled, starting MobDebug...");
        auto hostEnv = std::getenv("MOBDEBUG_HOST");
        auto portEnv = std::getenv("MOBDEBUG_PORT");
        std::string host = hostEnv ? std::string(hostEnv) : "localhost";
        int port = portEnv ? std::atoi(portEnv) : 8172;
        startMobdebug(host.c_str(), port);
    }

    global_state["__args"] = args;

    sol::protected_function_result result = global_state.safe_script("require('app://main.lua')", sol::script_pass_on_error);
    
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

void App::initMobdebug() {
    // Initialize mobdebug environment variables and functions
    global_state.set_function("start_mobdebug", [this](sol::optional<std::string> host, sol::optional<int> port) {
        std::string mobdebug_host = host.value_or("localhost");
        int mobdebug_port = port.value_or(8172);
        startMobdebug(mobdebug_host.c_str(), mobdebug_port);
    });
    
    global_state.set_function("stop_mobdebug", [this]() {
        stopMobdebug();
    });
    
    // Set up mobdebug environment
    global_state["MOBDEBUG_HOST"] = "localhost";
    global_state["MOBDEBUG_PORT"] = 8172;
    
    // Add mobdebug to package path if it exists
    std::string mobdebug_script = R"(
        -- Try to require mobdebug safely
        local function try_require_mobdebug()
            local success, mobdebug = pcall(require, 'mobdebug')
            if success then
                _G.mobdebug = mobdebug
                print("MobDebug loaded successfully")
                return true
            else
                print("MobDebug not found or failed to load: " .. tostring(mobdebug))
                return false
            end
        end
        
        -- Helper function to start debugging
        function start_debugging(host, port)
            if _G.mobdebug then
                _G.mobdebug.start(host or MOBDEBUG_HOST, port or MOBDEBUG_PORT)
                print("MobDebug started on " .. (host or MOBDEBUG_HOST) .. ":" .. (port or MOBDEBUG_PORT))
            else
                print("MobDebug not available")
            end
        end
        
        -- Helper function to stop debugging
        function stop_debugging()
            if _G.mobdebug then
                _G.mobdebug.done()
                print("MobDebug stopped")
            end
        end
        
        -- Try to load mobdebug
        try_require_mobdebug()
    )";
    
    sol::protected_function_result result = global_state.safe_script(mobdebug_script, sol::script_pass_on_error);
    if (!result.valid()) {
        sol::error err = result;
        UtilityFunctions::print("MobDebug initialization error: " + String(err.what()));
    }
}

void App::startMobdebug(const String& host, int port) {
    global_state["MOBDEBUG_HOST"] = host;
    global_state["MOBDEBUG_PORT"] = port;
    
    std::string start_script = String("start_debugging('" + host + "', " + String(std::to_string(port).c_str()) + ")").utf8().get_data();
    sol::protected_function_result result = global_state.safe_script(start_script, sol::script_pass_on_error);
    
    if (!result.valid()) {
        sol::error err = result;
        UtilityFunctions::print("Failed to start MobDebug: " + String(err.what()));
    }
}

void App::stopMobdebug() {
    sol::protected_function_result result = global_state.safe_script("stop_debugging()", sol::script_pass_on_error);
    
    if (!result.valid()) {
        sol::error err = result;
        UtilityFunctions::print("Failed to stop MobDebug: " + String(err.what()));
    }
}

namespace sunaba {
    void bindRuntime(sol::state& lua) {
        auto ut = lua.new_usertype<Runtime>("Runtime"
            "new", sol::factories(
                []() { return new Runtime(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element>(),
            "args", sol::property(
                &Runtime::getArgs,
                &Runtime::setArgs
            ),
            "init", sol::factories(
                [](Runtime* rt) { rt->initState(); },
                [](Runtime* rt, bool sandboxed) { rt->initState(sandboxed); }
            ),
            "load", &Runtime::loadAndExecuteSbx,
            "initMobdebug", &Runtime::initMobdebug,
            "startMobdebug", sol::factories(
                [](Runtime* rt) { rt->startMobdebug(); },
                [](Runtime* rt, const std::string host ) { rt->startMobdebug(host); },
                [](Runtime* rt, const std::string host, int port ) { rt->startMobdebug(host, port); }
            ),
            "stopMobdebug", &Runtime::stopMobdebug,
            "cast", [](Element* element) {
                auto* ce = dynamic_cast<Runtime*>(element);
                if (ce != nullptr) {
                    return ce;
                }
                App* node = Object::cast_to<App>(element->getNode());
                return new Runtime(node);
            }
        );
        lua["Runtime"] = ut;
    }
}