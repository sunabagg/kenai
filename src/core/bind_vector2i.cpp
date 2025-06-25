#include "lua_bind.h"

void lucidfx::core::bind_vector2i(sol::state& lua) {
    lua.new_usertype<godot::Vector2i>(
        "Vector2i", 
        sol::constructors<
            Vector2i(), 
            Vector2i(int, int)>(), 
            "x", &Vector2i::x, 
            "y", &Vector2i::y,
            "abs", &Vector2i::abs,
            "aspect", &Vector2i::aspect,
            "clamp", &Vector2i::clamp,
            //"distanceSquaredTo", &Vector2i::distance_squared_to,
            //"distanceTo", &Vector2i::distance_to,
            "length", &Vector2i::length,
            "lengthSquared", &Vector2i::length_squared,
            "max", &Vector2i::max,
            "maxAxisIndex", &Vector2i::max_axis_index,
            "min", &Vector2i::min,
            "minAxisIndex", &Vector2i::min_axis_index,
            "sign", &Vector2i::sign,
            "tostring", [](const Vector2i& v) { return std::string((v.operator String()).utf8().get_data()); }
            //"snapped", &Vector2i::snapped
    );
}