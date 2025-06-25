#include "lua_bind.h"

void lucidfx::core::bind_vector4i(sol::state& lua) {
    lua.new_usertype<godot::Vector4i>(
        "Vector4i",
        sol::constructors<Vector4i(), Vector4i(int, int, int, int)>(),
        "x", &Vector4i::x,
        "y", &Vector4i::y,
        "z", &Vector4i::z,
        "w", &Vector4i::w,
        "abs", &Vector4i::abs,
        "clamp", &Vector4i::clamp,
        //"distanceSquaredTo", &Vector4i::distance_squared_to,
        //"distanceTo", &Vector4i::distance_to,
        "length", &Vector4i::length,
        "lengthSquared", &Vector4i::length_squared,
        "max", &Vector4i::max,
        "maxAxisIndex", &Vector4i::max_axis_index,
        "min", &Vector4i::min,
        "minAxisIndex", &Vector4i::min_axis_index,
        "sign", &Vector4i::sign,
        "tostring", [](const Vector4i& v) { return std::string((v.operator String()).utf8().get_data()); }
        //"snapped", &Vector4i::snapped
    );
}