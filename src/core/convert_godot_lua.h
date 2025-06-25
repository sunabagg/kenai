#ifndef CONVERT_GODOT_LUA_H
#define CONVERT_GODOT_LUA_H

#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

using namespace godot;

namespace lucidware::core {
    Variant to_variant(const sol::object& object);
    Variant to_variant(const sol::stack_object& object);
    Variant to_variant(const sol::stack_proxy_base& object);    
    Variant to_variant(const sol::protected_function_result& function_result);
    Variant to_variant(const sol::load_result& load_result);
    Variant to_variant(lua_State *L, int index);
    template<typename ref_t>
    Variant to_variant(const sol::basic_object<ref_t>& object);
    sol::stack_object to_lua(lua_State *lua_state, const Variant& value);

    Array to_array(const sol::variadic_args& args);
    Array to_array(const sol::table& table);
    Dictionary to_dictionary(const sol::table& table);
    sol::table to_table(sol::state_view& state, const Dictionary& dictionary);
    sol::table to_table(sol::state_view& state, const Array& array);
}

#endif // CONVERT_GODOT_LUA_H