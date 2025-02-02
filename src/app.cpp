//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include"core/lua_bind.h"

using namespace newhaven;
using namespace godot;

void App::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start"), &App::start);
}

App::App() {
}

App::~App() {
    //UtilityFunctions::print("App destructor");
}

void App::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
                                     sol::lib::count, sol::lib::math, sol::lib::string,
                                     sol::lib::table, sol::lib::utf8 );

    global_state["print"] = [this]( sol::variadic_args args ) {
        String msg;
        for ( const auto &arg : args )
        {
            if ( arg.is<std::string>() )
            {
                std::string str = arg.as<std::string>();
                msg += str.c_str();
            }
        }
        godot::UtilityFunctions::print( msg );
    };

    UtilityFunctions::print("Hello, World!");

    //newhaven_core::bind_all_godot_classes( global_state );
    newhaven_core::initialize_lua( global_state );
}

void App::start() {
}