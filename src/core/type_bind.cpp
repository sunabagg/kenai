//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <vector>

using namespace godot;
using namespace sunaba::core;

void sunaba::core::bind_base_types(sol::state& lua) {
    bind_varaint(lua);
    bind_array_list(lua);
    bind_dictionary(lua);
    bind_vector2(lua);
    bind_rect2(lua);
    bind_vector2i(lua);
    bind_rect2i(lua);
    bind_vector3(lua);
    
    
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
    
    lua.new_usertype<godot::Vector4>(
        "Vector4",
        sol::constructors<Vector4(), Vector4(float, float, float, float)>(),
        "x", &Vector4::x,
        "y", &Vector4::y,
        "z", &Vector4::z,
        "w", &Vector4::w,
        "abs", &Vector4::abs,
        "ceil", &Vector4::ceil,
        "clamp", &Vector4::clamp,
        "cubicInterpolate", &Vector4::cubic_interpolate,
        "cubicInterpolateInTime", &Vector4::cubic_interpolate_in_time,
        "directionTo", &Vector4::direction_to,
        "distanceSquaredTo", &Vector4::distance_squared_to,
        "distanceTo", &Vector4::distance_to,
        "dot", &Vector4::dot,
        "floor", &Vector4::floor,
        "inverse", &Vector4::inverse,
        "isEqualApprox", &Vector4::is_equal_approx,
        //"isFinite", &Vector4::is_finite,
        "isNormalized", &Vector4::is_normalized,
        "isZeroApprox", &Vector4::is_zero_approx,
        "length", &Vector4::length,
        "lengthSquared", &Vector4::length_squared,
        "lerp", &Vector4::lerp,
        "max", &Vector4::max,
        "maxAxisIndex", &Vector4::max_axis_index,
        "min", &Vector4::min,
        "minAxisIndex", &Vector4::min_axis_index,
        "normalized", &Vector4::normalized,
        "posmod", &Vector4::posmod,
        "posmodv", &Vector4::posmodv,
        "round", &Vector4::round,
        "sign", &Vector4::sign,
        "snapped", &Vector4::snapped,
        "tostring", [](const Vector4& v) { return std::string((v.operator String()).utf8().get_data()); }
    );

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

    lua.new_usertype<godot::AABB>(
        "AABB",
        sol::constructors<
            AABB(), 
            AABB(Vector3, Vector3)>(),
        "end", sol::property(
            [](AABB& self) { 
                return self.get_end(); 
            }, 
            [](AABB& self, Vector3 value) { 
                self.set_end(value); 
            }
        ),
        "position", &AABB::position,
        "size", &AABB::size,
        "abs", &AABB::abs,
        "encloses", &AABB::encloses,
        "getCenter", &AABB::get_center,
        "getEndpoint", &AABB::get_endpoint,
        "getLongestAxis", &AABB::get_longest_axis,
        "getLongestAxisIndex", &AABB::get_longest_axis_index,
        "getLongestAxisSize", &AABB::get_longest_axis_size, 
        "getShortestAxis", &AABB::get_shortest_axis,
        "getShortestAxisIndex", &AABB::get_shortest_axis_index,
        "getShortestAxisSize", &AABB::get_shortest_axis_size,
        "getSupport", &AABB::get_support,
        "getVolume", &AABB::get_volume,
        "grow", &AABB::grow,
        "hasPoint", &AABB::has_point,
        "hasSurface", &AABB::has_surface,
        "hasVolume", &AABB::has_volume,
        "intersection", &AABB::intersection,
        "intersects", &AABB::intersects,
        "intersectsPlane", &AABB::intersects_plane,
        "intersectsRay", &AABB::intersects_ray,
        "isEqualApprox", &AABB::is_equal_approx,
        //"isFinite", &AABB::is_finite,
        "merge", &AABB::merge,
        "tostring", [](const AABB& a) { return std::string((a.operator String()).utf8().get_data()); }
    );

    lua.new_usertype<godot::Color>(
        "Color",
        sol::constructors<
            Color(), 
            Color(float, float, float),
            Color(float, float, float, float),
            Color(Color, float),
            Color(String),
            Color(String, float)>(),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a,
        //"s", &Color::s,
        //"v", &Color::v,
        //"h", &Color::h,
        "blend", &Color::blend,
        "clamp", &Color::clamp,
        "darkened", &Color::darkened,
        "fromHSV", &Color::from_hsv,
        //"fromOkHsl", &Color::from_ok_hsl,
        "fromRGBE9995", &Color::from_rgbe9995,
        "fromString", &Color::from_string,
        "getLuminance", &Color::get_luminance,
        "hex", &Color::hex,
        "hex64", &Color::hex64,
        "html", &Color::html,
        "htmlIsValid", &Color::html_is_valid,
        "inverted", &Color::inverted,
        "isEqualApprox", &Color::is_equal_approx,
        "lerp", &Color::lerp,
        "lightened", &Color::lightened,
        "linearToSrgb", &Color::linear_to_srgb,
        "SrgbToLinear", &Color::srgb_to_linear,
        "toAbgr32", &Color::to_abgr32,
        "toAbgr64", &Color::to_abgr64,
        "toArgb32", &Color::to_argb32,
        "toArgb64", &Color::to_argb64,
        "toHtml", &Color::to_html,
        "toRgba32", &Color::to_rgba32,
        "toRgba64", &Color::to_rgba64,
        "tostring", [](const Color& c) { return std::string((c.operator String()).utf8().get_data()); }
    );
}
