//
// Created by mintkat on 2/1/25.
//

#ifndef LUA_BIND_H
#define LUA_BIND_H

#include <godot_cpp/classes/object.hpp>
#include <sol/sol.hpp>

using namespace godot;

namespace sunaba::core
{
    void bind_class_to_lua(sol::state& lua, const String& class_name);

    void bind_all_godot_classes(sol::state& lua);

    void bind_base_types(sol::state& lua);

    void bind_varaint(sol::state& lua);

    void bind_array_list(sol::state& lua);

    void bind_dictionary(sol::state& lua);

    void bind_vector2(sol::state& lua);

    void bind_rect2(sol::state& lua);

    void bind_vector2i(sol::state& lua);

    void bind_rect2i(sol::state& lua);

    void bind_vector3(sol::state& lua);

    void bind_vector3i(sol::state& lua);

    void bind_vector4(sol::state& lua);

    void bind_vector4i(sol::state& lua);

    void bind_quaternion(sol::state& lua);

    void bind_basis(sol::state& lua);

    void bind_transform3d(sol::state& lua);

    void bind_aabb(sol::state& lua);

    void bind_color(sol::state& lua);

    void bind_packedcolorarray(sol::state& lua);

    void initialize_lua(sol::state& lua);
}

#endif //LUA_BIND_H
