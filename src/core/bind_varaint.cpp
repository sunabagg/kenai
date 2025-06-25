#include "lua_bind.h"
#include "io/binary_data.h"
#include "resource.h"
#include "element.h"
#include "base_object_proxy.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>

void lucidfx::core::bind_varaint(sol::state& lua) {
    lua.new_usertype<Variant>("Variant",
        sol::constructors<
            Variant(), 
            Variant(int), 
            Variant(float), 
            Variant(bool),
            //Variant(long), 
            //Variant(double), 
            Variant(String), 
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
         "fromObject", [](BaseObject* obj) { 
            BaseObjectProxy* proxy = memnew(BaseObjectProxy);
            proxy->base_object = obj;
            return Variant(proxy);
         },
         "fromInt64", [](int64_t value) { 
            return Variant(value); 
         },
         "fromFloat64", [](double value) { 
            return Variant(value); 
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
        "asObject", [](const Variant& v) { 
            Object* gdobj = v.operator Object*();
            if (gdobj) {
                BaseObjectProxy* proxy  = Object::cast_to<BaseObjectProxy>(gdobj);
                if (proxy) {
                    return proxy->base_object;
                }
            }
            return static_cast<lucidfx::core::BaseObject*>(nullptr);
         },
        "tostring", [](const Variant& v) { return std::string((v.operator String()).utf8().get_data()); }
    );
}