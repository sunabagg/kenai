#ifndef SOL_GDSTR_H
#define SOL_GDSTR_H

#include <godot_cpp/variant/string.hpp>
#include <sol/sol.hpp>

template <typename Handler>
bool sol_lua_check(sol::types<godot::String>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    int absolute_index = lua_absindex(L, index);
    bool success = sol::stack::check<std::string>(L, absolute_index, handler, tracking);
    tracking.use(1);
    return success;
}

godot::String sol_lua_get(sol::types<godot::String>, lua_State* L, int index, sol::stack::record& tracking) {
    int absolute_index = lua_absindex(L, index);
    const std::string& str = sol::stack::get<std::string>(L, absolute_index, tracking);
    tracking.use(1);
    return godot::String(str.c_str());
}

int sol_lua_push(sol::types<godot::String>, lua_State* L, godot::String str) {
    godot::CharString utf8 = str.utf8();
    return sol::stack::push<std::string>(L, std::string(utf8.get_data()));
}

#endif // SOL_GDSTR_H
