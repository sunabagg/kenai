//
// Created by mintkat on 2/1/25.
//

#ifndef LUA_BIND_H
#define LUA_BIND_H

#include <godot_cpp/classes/object.hpp>
#include <sol/sol.hpp>

using namespace godot;

namespace newhaven_core
{
    void bind_class_to_lua(sol::state& lua, const String& class_name);

    void bind_all_godot_classes(sol::state& lua);

    void bind_base_types(sol::state& lua);

    void initialize_lua(sol::state& lua);
}

#endif //LUA_BIND_H
