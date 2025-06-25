//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <vector>

using namespace godot;
using namespace lucidfx::core;

void lucidfx::core::bind_base_types(sol::state& lua) {
    bind_varaint(lua);
    bind_array_list(lua);
    bind_dictionary(lua);
    bind_vector2(lua);
    bind_rect2(lua);
    bind_vector2i(lua);
    bind_rect2i(lua);
    bind_vector3(lua);
    bind_vector3i(lua);
    bind_vector4(lua);
    bind_vector4i(lua);
    bind_quaternion(lua);
    bind_transform3d(lua);
    bind_aabb(lua);
    bind_color(lua);
}
