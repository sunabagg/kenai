#ifndef SOL_GDSTR_H
#define SOL_GDSTR_H

#include <godot_cpp/variant/string.hpp>
#include <sol/sol.hpp>

using namespace godot;

template <typename Handler>
bool sol_lua_check(sol::types<String>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    int absolute_index = lua_absindex(L, index);
    bool success = sol::stack::check<const char*>(L, absolute_index, handler, tracking);
    tracking.use(1);
    return success;
}

String sol_lua_get(sol::types<String>, lua_State* L, int index, sol::stack::record& tracking) {
    int absolute_index = lua_absindex(L, index);
    const char* str = sol::stack::get<const char*>(L, absolute_index, tracking);
    tracking.use(1);
    return String(str);
}

int sol_lua_push(sol::types<String>, lua_State* L, String str) {
    const char* cstr = str.utf8().get_data();
    return sol::stack::push<const char*>(L, cstr);
}

#endif // SOL_GDSTR_H