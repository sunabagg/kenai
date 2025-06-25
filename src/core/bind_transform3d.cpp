#include "lua_bind.h"

void lucidware::core::bind_transform3d(sol::state& lua) {
    lua.new_usertype<godot::Transform3D>(
        "Transform3D",
        sol::constructors<Transform3D(), Transform3D(Basis, Vector3)>(),
        "basis", &Transform3D::basis,
        "origin", &Transform3D::origin,
        "affineInverse", &Transform3D::affine_inverse,
        "interpolateWith", &Transform3D::interpolate_with,
        "isEqualApprox", &Transform3D::is_equal_approx,
        //"isFinite", &Transform3D::is_finite,
        "lookingAt", &Transform3D::looking_at,
        "orthonormalized", &Transform3D::orthonormalized,
        "rotated", &Transform3D::rotated,
        "rotatedLocal", &Transform3D::rotated_local,
        "scaled", &Transform3D::scaled,
        "scaledLocal", &Transform3D::scaled_local,
        "translated", &Transform3D::translated,
        "translatedLocal", &Transform3D::translated_local,
        "tostring", [](const Transform3D& t) { return std::string((t.operator String()).utf8().get_data()); }
    );
}