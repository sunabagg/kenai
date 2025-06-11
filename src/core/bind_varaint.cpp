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

void sunaba::core::bind_varaint(sol::state& lua) {
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
            Variant(Dictionary),
            Variant(PackedColorArray),
            Variant(PackedFloat32Array),
            Variant(PackedFloat64Array),
            Variant(PackedInt32Array),
            Variant(PackedInt64Array),
            Variant(PackedStringArray),
            Variant(PackedVector2Array),
            Variant(PackedVector3Array),
            Variant(PackedVector4Array)
        >(),
        "fromByteArray", [](const io::BinaryData& data) { return Variant(data.toPackedByteArray()); },
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
        "asPackedColorArray", &Variant::operator PackedColorArray,
        "asPackedFloat32Array", &Variant::operator PackedFloat32Array,
        "asPackedFloat64Array", &Variant::operator PackedFloat64Array,
        "asPackedInt32Array", &Variant::operator PackedInt32Array,
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
            return static_cast<sunaba::core::BaseObject*>(nullptr);
         },
        "tostring", [](const Variant& v) { return std::string((v.operator String()).utf8().get_data()); }
    );
}