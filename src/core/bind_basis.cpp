#include "lua_bind.h"

void lucidware::core::bind_basis(sol::state& lua) {
    lua.new_usertype<godot::Basis>(
        "Basis",
        sol::constructors<Basis(), Basis(Vector3, Vector3, Vector3)>(),
        "rows" , sol::property(
            [](Basis& self) { 
                auto rows = self.rows;
                std::vector<Vector3> vecs;
                vecs.push_back(rows[0]);
                vecs.push_back(rows[1]);
                vecs.push_back(rows[2]);
                return vecs;
            }, 
            [](Basis& self, const std::vector<Vector3>& value) { 
                self.rows[0] = value[0];
                self.rows[1] = value[1];
                self.rows[2] = value[2];
            }
        ),
        "determinant", &Basis::determinant,
        "fromEuler", &Basis::from_euler,
        "fromScale", &Basis::from_scale,
        "getEuler", &Basis::get_euler,
        "getRotationQuaternion", &Basis::get_rotation_quaternion,
        "getScale", &Basis::get_scale,
        "inverse", &Basis::inverse,
        //"isConformal", &Basis::is_conformal,
        "isEqualApprox", &Basis::is_equal_approx,
        //"isFinite", &Basis::is_finite,
        "lookingAt", &Basis::looking_at,
        "orthonormalized", &Basis::orthonormalized,
        //"rotated", &Basis::rotated,
        "scaled", &Basis::scaled,
        "slerp", &Basis::slerp,
        "tdotx", &Basis::tdotx,
        "tdoty", &Basis::tdoty,
        "tdotz", &Basis::tdotz,
        "transposed", &Basis::transposed,
        "tostring", [](const Basis& b) { return std::string((b.operator String()).utf8().get_data()); }
    );
}