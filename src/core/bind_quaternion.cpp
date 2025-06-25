#include "lua_bind.h"

void lucidware::core::bind_quaternion(sol::state& lua) {
    lua.new_usertype<godot::Quaternion> (
        "Quaternion",
        sol::constructors<Quaternion(), Quaternion(float, float, float, float)>(),
        "x", &Quaternion::x,
        "y", &Quaternion::y,
        "z", &Quaternion::z,
        "w", &Quaternion::w,
        "angleTo", &Quaternion::angle_to,
        "dot", &Quaternion::dot,
        "exp", &Quaternion::exp,
        //"fromEuler", &Quaternion::from_euler,
        "inverse", &Quaternion::inverse,
        "isEqualApprox", &Quaternion::is_equal_approx,
        "isNormalized", &Quaternion::is_normalized,
        "length", &Quaternion::length,
        "lengthSquared", &Quaternion::length_squared,
        "log", &Quaternion::log,
        "normalized", &Quaternion::normalized,
        "slerp", &Quaternion::slerp,
        "sphericalCubicInterpolate", &Quaternion::spherical_cubic_interpolate,
        "sphericalLinearInterpolateInTime", &Quaternion::spherical_cubic_interpolate_in_time,
        "tostring", [](const Quaternion& q) { return std::string((q.operator String()).utf8().get_data()); }
    );
}