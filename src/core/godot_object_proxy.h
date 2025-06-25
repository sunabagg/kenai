#ifndef GODOT_OBJECT_PROXY_H
#define GODOT_OBJECT_PROXY_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/object.hpp>
#include <sol/sol.hpp>

using namespace godot;

namespace lucidfx::core{
    struct GodotObjectProxy
    {
        Object* object;

        String className;

        GodotObjectProxy(Object* object) : object(object) {}

        GodotObjectProxy(String name) : className(name), object(ClassDB::instantiate(name)) {}

        sol::object get(sol::stack_object key, sol::this_state L);

        void set(sol::stack_object key, sol::stack_object value,
	     sol::this_state);
    };
    
}

#endif