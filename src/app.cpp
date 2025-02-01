//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

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

    UtilityFunctions::print("Hello, World!");
}

void App::start() {
}