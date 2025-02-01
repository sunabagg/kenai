//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;
using namespace newhaven_core;

void newhaven_core::bind_class_to_lua(sol::state& lua, const String& class_name) {
    // Get class info
    if (!ClassDB::class_exists(class_name)) {
        godot::UtilityFunctions::print("Class not found: ", class_name);
        return;
    }

    // Create a new Lua usertype
    lua.new_usertype<godot::Object>(
        class_name.utf8().get_data(),
        sol::constructors<>()
    );

    // Get method list
    List<MethodInfo> method_list;
    List<MethodInfo>* method_list_ptr = &method_list;
    ClassDB::class_get_method_list(class_name, method_list_ptr);

    // Iterate through methods and bind them
    for (const MethodInfo& method : method_list) {
        lua[class_name.utf8().get_data()][((String)method.name).utf8().get_data()] =
            [class_name, method](godot::Object* obj, sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }
                return obj->call(method.name, args);
        };
    }
}

void newhaven_core::bind_all_godot_classes(sol::state& lua) {
    List<StringName> all_classes;
    ClassDB::get_class_list();

    for (const StringName& class_name : all_classes) {
        if (class_name == String("OS") || class_name == String("DisplayServer") ||
            class_name == String("RenderingDevice") || class_name == String("FileAccess")) {
            continue; // Exclude core engine classes
            }
        bind_class_to_lua(lua, class_name);
    }
}

void newhaven_core::initialize_lua(sol::state& lua) {
    bind_all_godot_classes(lua);

    lua.script(R"(
        local node = Node.new()
        print(node:get_name())  -- Example usage
    )");
}