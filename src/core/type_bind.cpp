//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"
#include "io/binary_data.h"
#include "resource.h"
#include "element.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <vector>

using namespace godot;
using namespace sunaba::core;

void sunaba::core::bind_base_types(sol::state& lua) {
    lua.new_usertype<Variant>("Variant",
        sol::constructors<
            Variant(), 
            Variant(int), 
            Variant(float), 
            Variant(bool),
            Variant(long), 
            Variant(double), 
            Variant(char*), 
            Variant(Vector2), 
            Variant(Vector2i), 
            Variant(Rect2), 
            Variant(Rect2i),
            Variant(Basis),
            Variant(Vector3),
            Variant(Vector3i),
            Variant(Transform2D),
            Variant(Vector4),
            Variant(Vector4i),
            Variant(Plane),
            Variant(Quaternion),
            Variant(AABB),
            Variant(Projection),
            Variant(Array),
            Variant(Dictionary)>(),
        "fromByteArray", [](const io::BinaryData& data) { return Variant(data.toPackedByteArray()); },
        "fromIntArray", [](const std::vector<int>& data) { 
            PackedInt32Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
         },
         "fromIntArray64", [](const std::vector<int64_t>& data) { 
            PackedInt64Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
         },
         "fromFloatArray", [](const std::vector<float>& data) { 
            PackedFloat32Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
         },
         "fromFloatArray64", [](const std::vector<double>& data) { 
            PackedFloat64Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
         },
         "fromStringArray", [](const std::vector<String>& data) { 
            PackedStringArray packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
         },
        "fromVector2Array", [](const std::vector<Vector2>& data) { 
            PackedVector2Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
        },
        "fromVector3Array", [](const std::vector<Vector3>& data) { 
            PackedVector3Array packed_data;
            for (const auto& item : data) {
                packed_data.append(item);
            }
            return Variant(packed_data);
        },
        "fromElement", [](const Element* e) { 
            godot::Node* n = e->getNode();
            if (n) {
                return Variant(n);
            } else {
                return Variant();
            }
         },
        "fromResource", [](const Resource* resource) { 
            godot::Resource* res = resource->getResource();
            godot::Ref<godot::Resource> ref = godot::Ref<godot::Resource>(res);
            return Variant(ref);
         },
        "getType", &Variant::get_type,
        "getTypeName", &Variant::get_type_name,
        "asString", [](const Variant& v) { return std::string((v.operator String()).utf8().get_data()); },
        "asInt", &Variant::operator int,
        "asFloat", &Variant::operator float,
        "asBool", &Variant::operator bool,
        "asVector2", &Variant::operator Vector2,
        "asVector2i", &Variant::operator Vector2i,
        "asRect2", &Variant::operator Rect2,
        "asRect2i", &Variant::operator Rect2i,
        "asBasis", &Variant::operator Basis,
        "asVector3", &Variant::operator Vector3,
        "asVector3i", &Variant::operator Vector3i,
        "asTransform2D", &Variant::operator Transform2D,
        "asVector4", &Variant::operator Vector4,
        "asVector4i", &Variant::operator Vector4i,
        "asPlane", &Variant::operator Plane,
        "asQuaternion", &Variant::operator Quaternion,
        "asAABB", &Variant::operator godot::AABB,
        "asProjection", &Variant::operator Projection,
        "asArray", &Variant::operator Array,
        "asDictionary", &Variant::operator Dictionary,
        "asByteArray", [](const Variant& v) { return io::BinaryData(v); },
        "asIntArray", [](const Variant& v) { 
            PackedInt32Array packed_data = v;
            std::vector<int> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asIntArray64", [](const Variant& v) { 
            PackedInt64Array packed_data = v;
            std::vector<int64_t> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asFloatArray", [](const Variant& v) { 
            PackedFloat32Array packed_data = v;
            std::vector<float> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asFloatArray64", [](const Variant& v) { 
            PackedFloat64Array packed_data = v;
            std::vector<double> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asStringArray", [](const Variant& v) { 
            PackedStringArray packed_data = v;
            std::vector<String> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asVector2Array", [](const Variant& v) { 
            PackedVector2Array packed_data = v;
            std::vector<Vector2> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asVector3Array", [](const Variant& v) { 
            PackedVector3Array packed_data = v;
            std::vector<Vector3> data;
            for (int i = 0; i < packed_data.size(); ++i) {
                data.push_back(packed_data[i]);
            }
            return data;
        },
        "asElement", [](const Variant& v) { 
            godot::Object* obj = v.operator Object*();
            Node* n = Object::cast_to<Node>(obj);
            if (n) {
                return Element(n);
            } else {
                return Element();
            }
         },
        "asResource", [](const Variant& v) { 
            Object* obj = v.operator Object*();
            Ref<godot::Resource> res = Object::cast_to<godot::Resource>(obj);
            if (res.ptr()) {
                return Resource(res.ptr());
            } else {
                return Resource();
            }
         },
        "tostring", [](const Variant& v) { return std::string((v.operator String()).utf8().get_data()); }
    );

    lua.new_usertype<Array>("Array",
        sol::constructors<Array()>(),
        "append", &Array::append,
        "appendArray", &Array::append_array,
        "assign", &Array::assign,
        "back", &Array::back,
        "bsearch", &Array::bsearch,
        "clear", &Array::clear,
        "count", &Array::count,
        "duplicate", &Array::duplicate,
        "erase", &Array::erase,
        "fill", &Array::fill,
        "filter", &Array::filter,
        "find", &Array::find,
        "front", &Array::front,
        "get", &Array::get,
        "has", &Array::has,
        "hash", &Array::hash,
        "insert", &Array::insert,
        "isEmpty", &Array::is_empty,
        "isReadOnly", &Array::is_read_only,
        "makeReadOnly", &Array::make_read_only,
        "max", &Array::max,
        "min", &Array::min,
        "pickRandom", &Array::pick_random,
        "popAt", &Array::pop_at,
        "popBack", &Array::pop_back,
        "popFront", &Array::pop_front,
        "pushBack", &Array::push_back,
        "pushFront", &Array::push_front,
        "removeAt", &Array::remove_at,
        "resize", &Array::resize,
        "reverse", &Array::reverse,
        "rfind", &Array::rfind,
        "set", &Array::set,
        "shuffle", &Array::shuffle,
        "size", &Array::size,
        "slice", &Array::slice,
        "sort", &Array::sort,
        sol::meta_function::index, [](Array& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](Array& arr, int index, const Variant& value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &Array::size,
        "__pairs", [](Array& arr) {
            return sol::as_function([&arr, i = 0](sol::this_state& s) mutable -> std::tuple<sol::object, sol::object> {
            if (i < arr.size()) {
                return { sol::make_object(s, i), sol::make_object(s, arr[i++]) };
            } else {
                return { sol::lua_nil, sol::lua_nil };
            }
            });
        },
        "__ipairs", [](Array& arr) {
            return sol::as_function([](sol::this_state& s, Array& a, int i) -> std::tuple<sol::object, sol::object> {
                i++;
                if (i <= a.size()) {
                    return { sol::make_object(s, i), sol::make_object(s, a[i - 1]) };
                }
                return { sol::lua_nil, sol::lua_nil };
            });
        },
        sol::meta_function::to_string, [](const Array& arr) {
            return "<Array size=" + std::to_string(arr.size()) + ">";
        }
        
    );

    lua.new_usertype<Dictionary>("Dictionary",
        sol::constructors<Dictionary()>(),
        "assign", &Dictionary::assign,
        "clear", &Dictionary::clear,
        "duplicate", &Dictionary::duplicate,
        "erase", &Dictionary::erase,
        "findKey", &Dictionary::find_key,
        "get", &Dictionary::get,
        "getOrAdd", &Dictionary::get_or_add,
        "has", &Dictionary::has,
        "hasAll", &Dictionary::has_all,
        "hash", &Dictionary::hash,
        "isEmpty", &Dictionary::is_empty,
        "isReadOnly", &Dictionary::is_read_only,
        "keys", &Dictionary::keys,
        "makeReadOnly", &Dictionary::make_read_only,
        "merge", &Dictionary::merge,
        "merged", &Dictionary::merged,
        "recursiveEqual", &Dictionary::recursive_equal,
        "set", &Dictionary::set,
        "size", &Dictionary::size,
        "sort", &Dictionary::sort,
        "values", &Dictionary::values,
        "__pairs", [](Dictionary& dict) {
            return sol::as_function([&dict, i = 0](sol::this_state& s) mutable -> std::tuple<sol::object, sol::object> {
            if (i < dict.size()) {
                return { sol::make_object(s, dict.keys()[i]), sol::make_object(s, dict.values()[i++]) };
            } else {
                return { sol::lua_nil, sol::lua_nil };
            }
            });
        },
        "__ipairs", [](Dictionary& dict) {
            return sol::as_function([](sol::this_state& s, Dictionary& d, int i) -> std::tuple<sol::object, sol::object> {
                i++;
                if (i <= d.size()) {
                    return { sol::make_object(s, d.keys()[i - 1]), sol::make_object(s, d.values()[i - 1]) };
                }
                return { sol::lua_nil, sol::lua_nil };
            });
        },
        sol::meta_function::index, [](Dictionary& dict, const Variant& key) { return dict[key]; },
        sol::meta_function::new_index, [](Dictionary& dict, const Variant& key, const Variant& value) {
            dict.set(key, value);
        },
        sol::meta_function::length, &Dictionary::size,
        sol::meta_function::to_string, [](const Dictionary& dict) {
            return "<Dictionary size=" + std::to_string(dict.size()) + ">";
        }
    );

    lua.new_usertype<Vector2>(
        "Vector2",
        sol::constructors<Vector2(), Vector2(float, float)>(),
        "x", &Vector2::x,
        "y", &Vector2::y,
        "normalize", &Vector2::normalize,
        "normalized", &Vector2::normalized,
        "isNormalized", &Vector2::is_normalized,
        "length", &Vector2::length,
        "lengthSquared", &Vector2::length_squared,
        "limitLength", &Vector2::limit_length,
        "min", &Vector2::min,
        "max", &Vector2::max,
        "distanceTo", &Vector2::distance_to,
        "distanceSquaredTo", &Vector2::distance_squared_to,
        "angleTo", &Vector2::angle_to,
        "angleToPoint", &Vector2::angle_to_point,
        "dot", &Vector2::dot,
        "posmod", &Vector2::posmod,
        "posmodv", &Vector2::posmodv,
        "project", &Vector2::project,
        "planeProject", &Vector2::plane_project,
        "lerp", &Vector2::lerp,
        "slerp", &Vector2::slerp,
        "cubicInterpolate", &Vector2::cubic_interpolate,
        "cubicInterpolateInTime", &Vector2::cubic_interpolate_in_time,
        "bezierInterpolate", &Vector2::bezier_interpolate,
        "moveToward", &Vector2::move_toward,
        "slide", &Vector2::slide,
        "bounce", &Vector2::bounce,
        "reflect", &Vector2::reflect,
        "isEqualApprox", &Vector2::is_equal_approx,
        "isZeroApprox", &Vector2::is_zero_approx,
        "angle", &Vector2::angle,
        "abs", &Vector2::abs,
        "rotated", &Vector2::rotated,
        "orthogonal", &Vector2::orthogonal,
        "sign", &Vector2::sign,
        "floor", &Vector2::floor,
        "ceil", &Vector2::ceil,
        "round", &Vector2::round,
        "snapped", &Vector2::snapped,
        "clamp", &Vector2::clamp,
        "aspect", &Vector2::aspect,
        "tostring", [](const Vector2& v) { return std::string((v.operator String()).utf8().get_data()); }
        );
    
    lua.new_usertype<Rect2>(
        "Rect2",
        sol::constructors<
            Rect2(), 
            Rect2(Rect2i),
            Rect2(Vector2, Vector2), 
            Rect2(float, float, float, float)>(),
            "end", sol::property(
                [](Rect2& self) { 
                    return self.get_end(); 
                }, 
                [](Rect2& self, Vector2 value) { 
                    self.set_end(value); 
                }
            ),
            "position", &Rect2::position,
            "size", &Rect2::size,
            "abs", &Rect2::abs,
            "encloses", &Rect2::encloses,
            "expand", &Rect2::expand,
            "getArea", &Rect2::get_area,
            "getCenter", &Rect2::get_center,
            "grow", &Rect2::grow,
            "growIndividual", &Rect2::grow_individual,
            "growSide", &Rect2::grow_side,
            "hasArea", &Rect2::has_area,
            "hasPoint", &Rect2::has_point,
            "intersection", &Rect2::intersection,
            "intersects", &Rect2::intersects,
            "isEqualApprox", &Rect2::is_equal_approx,
            //"isFinite", &Rect2::is_finite,
            "merge", &Rect2::merge,
            "tostring", [](const Rect2& r) { return std::string((r.operator String()).utf8().get_data()); }
    );

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

    lua.new_usertype<godot::Rect2i>(
        "Rect2i", 
        sol::constructors<
            Rect2i(), 
            Rect2i(Vector2i, Vector2i),
            Rect2i(Rect2),
            Rect2i(int, int, int, int)>(),
            "position", &Rect2i::position, 
            "size", &Rect2i::size,
            "end", sol::property(
                [](Rect2i& self) {
                    return self.get_end();
                },
                [](Rect2i& self, Vector2i value) {
                    self.set_end(value);
                }
            ),
            "abs", &Rect2i::abs,
            "encloses", &Rect2i::encloses,
            "expand", &Rect2i::expand,
            "getArea", &Rect2i::get_area,
            "getCenter", &Rect2i::get_center,
            "grow", &Rect2i::grow,
            "growSide", &Rect2i::grow_side,
            "hasArea", &Rect2i::has_area,
            "hasPoint", &Rect2i::has_point,
            "intersection", &Rect2i::intersection,
            "intersects", &Rect2i::intersects,
            "tostring", [](const Rect2i& r) { return std::string((r.operator String()).utf8().get_data()); }
            //"isEqualApprox", &Rect2i::is_equal_approx,
    );

    lua.new_usertype<godot::Vector3>(
        "Vector3",
        sol::constructors<Vector3(), Vector3(float, float, float)>(),
        "x", &Vector3::x,
        "y", &Vector3::y,
        "z", &Vector3::z,
        "abs", &Vector3::abs,
        "angleTo", &Vector3::angle_to,
        //"bezierDerivative", &Vector3::bezier_derivative,
        "bezierInterpolate", &Vector3::bezier_interpolate,
        "bounce", &Vector3::bounce,
        "ceil", &Vector3::ceil,
        "clamp", &Vector3::clamp,
        //"clampf", &Vector3::clampf,
        "cross", &Vector3::cross,
        "cubicInterpolate", &Vector3::cubic_interpolate,
        "cubicInterpolateInTime", &Vector3::cubic_interpolate_in_time,
        "directionTo", &Vector3::direction_to,
        "distanceSquaredTo", &Vector3::distance_squared_to,
        "distanceTo", &Vector3::distance_to,
        "dot", &Vector3::dot,
        "floor", &Vector3::floor,
        "inverse", &Vector3::inverse,
        "isEqualApprox", &Vector3::is_equal_approx,
        //"isFinite", &Vector3::is_finite,
        "isNormalized", &Vector3::is_normalized,
        "isZeroApprox", &Vector3::is_zero_approx,
        "length", &Vector3::length,
        "lengthSquared", &Vector3::length_squared,
        "limitLength", &Vector3::limit_length,
        "lerp", &Vector3::lerp,
        "max", &Vector3::max,
        "maxAxisIndex", &Vector3::max_axis_index,
        "min", &Vector3::min,
        "minAxisIndex", &Vector3::min_axis_index,
        "moveToward", &Vector3::move_toward,
        "normalize", &Vector3::normalize,
        "normalized", &Vector3::normalized,
        "octahedronDecode", &Vector3::octahedron_decode,
        "octrahedronEncode", &Vector3::octahedron_encode,
        "outer", &Vector3::outer,
        "posmod", &Vector3::posmod,
        "posmodv", &Vector3::posmodv,
        "project", &Vector3::project,
        "reflect", &Vector3::reflect,
        "rotated", &Vector3::rotated,
        "round", &Vector3::round,
        "sign", &Vector3::sign,
        "signedAngleTo", &Vector3::signed_angle_to,
        "slerp", &Vector3::slerp,
        "slide", &Vector3::slide,
        "snapped", &Vector3::snapped,
        "tostring", [](const Vector3& v) { return std::string((v.operator String()).utf8().get_data()); }
        );
    
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
