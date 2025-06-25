#include "lua_bind.h"

void lucidfx::core::bind_vector3i(sol::state& lua) {
    lua.new_usertype<godot::Vector3i>(
        "Vector3i",
        sol::constructors<Vector3i(), Vector3i(int, int, int)>(),
        "x", &Vector3i::x,
        "y", &Vector3i::y,
        "z", &Vector3i::z,
        "abs", &Vector3i::abs,
        "clamp", &Vector3i::clamp,
        //"distanceSquaredTo", &Vector3i::distance_squared_to,
        //"distanceTo", &Vector3i::distance_to,
        "length", &Vector3i::length,
        "lengthSquared", &Vector3i::length_squared,
        "max", &Vector3i::max,
        "maxAxisIndex", &Vector3i::max_axis_index,
        "min", &Vector3i::min,
        "minAxisIndex", &Vector3i::min_axis_index,
        "sign", &Vector3i::sign,
        "tostring", [](const Vector3i& v) { return std::string((v.operator String()).utf8().get_data()); }
    );
}