#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/json.hpp>

#include "io/io_interface.h"


using namespace godot;

namespace sunaba::core {
    class DictEncoding : public Object {
        GDCLASS(DictEncoding, Object)
        protected:
            static void _bind_methods() {}

            static Array allowedClasses() {
                Array list;
                list.append("AudioStream");
                list.append("AudioStreamMicrophone");
                list.append("AudioStreamOggVorbis");
                list.append("AudioStreamPlaylist");
                list.append("AudioStreamPolyphonic");
                list.append("AudioStreamRandomizer");
                list.append("AudioStreamSyncronized");
                list.append("AudioStreamWav");
                list.append("AnimatedTexture");
                list.append("AtlasTexture");
                list.append("BitMap");
                list.append("CanvasItemMaterial");
                list.append("Environment");
                list.append("FontFile");
                list.append("FontVariation");
                list.append("Font");
                list.append("Gradient");
                list.append("ImageTexturedLayered");
                list.append("ImageTexture");
                list.append("Image");
                list.append("LabelSettings");
                list.append("Material");
                list.append("NoiseTexture2D");
                list.append("Noise");
                list.append("PlaceholderTextureLayered");
                list.append("PlaceholderTexture2DArray");
                list.append("PlaceholderTexture2D");
                list.append("Resource");
                list.append("ShaderInclude");
                list.append("ShaderMaterial");
                list.append("Shader");
                list.append("SystemFont");
                list.append("TextureCubemapArrayRD");
                list.append("TextureCubemapRD");
                list.append("TextureLayeredRD");
                list.append("TextureLayered");
                list.append("Texture");
                list.append("Texture2D");
                list.append("Texture2DRD");
                list.append("Translation");
                list.append("InputEvent");
                list.append("InputEventAction");
                list.append("InputEventFromWindow");
                list.append("InputEventGesture");
                list.append("InputEventJoypadButton");
                list.append("InputEventJoypadMotion");
                list.append("InputEventKey");
                list.append("InputEventMagnifyGesture");
                list.append("InputEventMidi");
                list.append("InputEventMouseButton");
                list.append("InputEventMouseMotion");
                list.append("InputEventMouse");
                list.append("InputEventPanGesture");
                list.append("InputEventScreenDrag");
                list.append("InputEventScreenTouch");
                list.append("InputEventWithModifiers");
                list.append("Shortcut");
                list.append("ArrayOccluder3D");
                list.append("BaseMaterial3D");
                list.append("BoxOccluder3D");
                list.append("CameraAttributesPhysical");
                list.append("CameraAttributesPractical");
                list.append("CameraAttributes");
                list.append("CubemapArray");
                list.append("Cubemap");
                list.append("Curve3D");
                list.append("FogMaterial");
                list.append("Occluder3D");
                list.append("OrmMaterial3D");
                list.append("PanoramaSkyMaterial");
                list.append("PhysicalSkyMaterial");
                list.append("PolygonOccluder3D");
                list.append("ProceduralSkyMaterial");
                list.append("QuadOccluder3D");
                list.append("SkeletonProfileHumanoid");
                list.append("SkeletonProfile");
                list.append("Skin");
                list.append("Sky");
                list.append("SphereOccluder3D");
                list.append("StandardMaterial3D");
                list.append("Texture3D");
                list.append("Texture3DRD");
                list.append("World3D");
                list.append("ButtonGroup");
                list.append("CodeHighlighter");
                list.append("StyleBoxEmpty");
                list.append("StyleBoxFlat");
                list.append("StyleBoxLine");
                list.append("StyleBoxTexture");
                list.append("StyleBox");
                list.append("SyntaxHighlighter");
                list.append("Theme");

                return list;
            }

            static Dictionary typenames() {
                Dictionary tn;
                tn["Nil"] = Variant::NIL;
                tn["bool"] = Variant::BOOL;
                tn["int"] = Variant::INT;
                tn["float"] = Variant::FLOAT;
                tn["String"] = Variant::STRING;
                tn["Vector2"] = Variant::VECTOR2;
                tn["Vector2i"] = Variant::VECTOR2I;
                tn["Rect2"] = Variant::RECT2;
                tn["Rect2i"] = Variant::RECT2I;
                tn["Vector3"] = Variant::VECTOR3;
                tn["Vector3i"] = Variant::VECTOR3I;
                tn["Transform2D"] = Variant::TRANSFORM2D;
                tn["Vector4"] = Variant::VECTOR4;
                tn["Vector4i"] = Variant::VECTOR4I;
                tn["Plane"] = Variant::PLANE;
                tn["Quaternion"] = Variant::QUATERNION;
                tn["AABB"] = Variant::AABB;
                tn["Basis"] = Variant::BASIS;
                tn["Transform3D"] = Variant::TRANSFORM3D;
                tn["Projection"] = Variant::PROJECTION;
                tn["Color"] = Variant::COLOR;
                tn["StringName"] = Variant::STRING_NAME;
                tn["NodePath"] = Variant::NODE_PATH;
                tn["RID"] = Variant::RID;
                tn["Object"] = Variant::OBJECT;
                tn["Callable"] = Variant::CALLABLE;
                tn["Signal"] = Variant::SIGNAL;
                tn["Dictionary"] = Variant::DICTIONARY;
                tn["Array"] = Variant::ARRAY;
                tn["PackedByteArray"] = Variant::PACKED_BYTE_ARRAY;
                tn["PackedInt32Array"] = Variant::PACKED_INT32_ARRAY;
                tn["PackedInt64Array"] = Variant::PACKED_INT64_ARRAY;
                tn["PackedFloat32Array"] = Variant::PACKED_FLOAT32_ARRAY;
                tn["PackedFloat64Array"] = Variant::PACKED_FLOAT64_ARRAY;
                tn["PackedStringArray"] = Variant::PACKED_STRING_ARRAY;
                tn["PackedVector2Array"] = Variant::PACKED_VECTOR2_ARRAY;
                tn["PackedVector3Array"] = Variant::PACKED_VECTOR3_ARRAY;
                tn["PackedVector4Array"] = Variant::PACKED_VECTOR4_ARRAY;
                return tn;
            }

            static bool _glob_filters(const String& value, Array list) {
                for (int i = 0; i < list.size(); i++) {
                    String expr = list[i];
                    if (value.match(expr))
                        return true; 
                }
                return false;
            }

            static Error _filter_class(const String& cname) {
                if (!_glob_filters(cname, allowedClasses())) {
                    return Error::ERR_UNAUTHORIZED;
                }
                if (!ClassDBSingleton::get_singleton()->class_exists(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                if (!ClassDBSingleton::get_singleton()->can_instantiate(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                return Error::OK;
            }

            static Error _filter_resource(const String& rpath, io::IoInterface* iointerface) {
                if (!iointerface->fileExists(rpath.utf8().get_data())) {
                    return Error::ERR_FILE_NOT_FOUND;
                }
                return Error::OK;
            }

            static bool isType(const String& t) {\
                Dictionary tn = typenames();
                for (int i = 0; i < tn.size(); i++)
                    if (tn.keys()[i] == t)
                        return true;
                return false;
            }

            static bool dicHas(Dictionary dic, const Variant& v) {
                Dictionary tn = typenames();
                for (int i = 0; i < tn.size(); i++)
                    if (tn.keys()[i] == v)
                        return true;
                return false;
            }

        public:
            static Dictionary encode_dict(const Variant& value, io::IoInterface* iointeface, Array dedup = Array(), bool recursed = false) {
                auto type = value.get_type();
                Dictionary dict;
                dict["\\T"] = value.get_type_name(type);
                auto pos = dedup.find(value);
                if (pos != -1) {
                    dict["\\R"] = pos;
                    return dict;
                }
                // Declare variables outside the switch to avoid bypassing initialization
                Object* obj = nullptr;
                Ref<Resource> res;
                TypedArray<Dictionary> property_list;
                Array arr;
                Array outArr;
                Error err = Error::OK;
                Dictionary dic;
                Dictionary outDic;

                switch (type)
                {
                    case Variant::OBJECT:
                        obj = value;
                        dedup.push_back(obj);
                        if (recursed && obj->is_class("Resource")) {
                            res = Ref<Resource>(
                                Object::cast_to<Resource>(
                                    obj
                                )
                            );
                            if (!res->get_path().is_empty() && iointeface->fileExists(res->get_path().utf8().get_data())) {
                                dict["\\P"] = res->get_path();
                                return dict;
                            }
                            dict["\\V"] = Dictionary();
                            property_list = obj->get_property_list();
                            for (int p = 0; p < property_list.size(); p++ ) {
                                const Dictionary& prop = property_list[p];
                                String pn = prop["name"];
                                if (pn == "script") continue;
                                if (!prop["usage"] && PROPERTY_USAGE_STORAGE) continue;
                                dict["\\V"] = encode_dict(obj->get(pn), iointeface, dedup, true);
                            }
                        }
                        break;
                    
                    case Variant::ARRAY:
                        arr = value;
                        outArr = Array();
                        err = static_cast<Error>(outArr.resize(arr.size()));
                        if (err != Error::OK) {
                            UtilityFunctions::push_error("Cannot allocate array");
                            return Dictionary();
                        }
                        for (int i = 0; i < arr.size(); i++) {
                            outArr[i] = encode_dict(arr[i], iointeface, dedup, true);
                        }
                        dict["\\AT"] = Variant::get_type_name(static_cast<Variant::Type>(arr.get_typed_builtin()));
                        dict["\\AC"] = arr.get_typed_class_name();
                        dict["\\V"] = outArr; 
                        break;
                
                    case Variant::DICTIONARY:
                        dic = value;
                        outDic = Dictionary();
                        for (int ki = 0; ki < dic.size(); ki++)
                        {
                            Variant k = dic.keys()[ki];
                            outDic[k] = encode_dict(dic[k], iointeface, dedup, true);
                        }
                        dic["\\KT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_key_builtin()));
                        dic["\\VT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_value_builtin()));
                        dic["\\VC"] = dic.get_typed_value_class_name();
                        dic["\\V"] = outDic;
                        break;
                        
                    default:
                        dic["\\V"] = value;
                        break;
                }
                return dict;
            }

            static Variant decode_dict(Dictionary dict, io::IoInterface* iointerface, Array dedup = Array()) {
                if (dict.has("\\R")) {
                    int64_t index = dict["\\R"];
                    return dedup[index];
                }
                if (!!dict.has("\\T")) {
                    UtilityFunctions::push_error("Dictionary does not contain key \\T");
                    return Error::ERR_FILE_CORRUPT;
                }
                if (dict["\\T"].get_type() != Variant::STRING) {
                    UtilityFunctions::push_error("\\T is not a string.");
                    return Error::ERR_FILE_CORRUPT;
                }
                String type = dict["\\T"];
                if (!dict.has("\\V") && dict.has("\\P")) {
                    UtilityFunctions::push_error("Dictionary does not contain key \\V");
                    return Error::ERR_FILE_CORRUPT;
                }
                if (!!isType(type)) {
                    UtilityFunctions::push_error("Type " + type + " not recognized");
                    return Error::ERR_FILE_CORRUPT;
                }
                int64_t typei64 = typenames()[type];
                Variant::Type typei = static_cast<Variant::Type>(typei64);
                switch (typei)
                {
                    case Variant::OBJECT:
                        if (!dicHas(dict, "\\C")) {
                            UtilityFunctions::push_error("Dictionary does not containe key \\C");
                            return Error::ERR_FILE_CORRUPT;
                        }
                        Variant& cnamev = dict["\\C"];
                        if (cnamev.get_type() != Variant::STRING) {
                            UtilityFunctions::push_error("\\C is not a string: " + String(cnamev));
                            return Error::ERR_FILE_CORRUPT;
                        }
                        String cname = cnamev;
                        Error ret = _filter_class(cname);
                        if (ret != Error::OK) 
                            return ret;
                        Object* res = ClassDBSingleton::get_singleton()->instantiate(cname);
                        dedup.push_back(res);
                        if (dicHas(dict, "\\P")) {
                            String ppath = dict["\\P"];
                            ret = _filter_resource(ppath, iointerface);
                            if (ret != Error::OK) 
                                return ret;
                            std::string resstr = iointerface->loadText(ppath.utf8().get_data());
                            Variant resjson = JSON::parse_string(resstr.c_str());
                            return decode_dict(resjson, iointerface);
                        }
                        Variant value = dict["\\V"];
                        if (value.get_type() != Variant::DICTIONARY) {
                            UtilityFunctions::push_error("\\V is not a Dictionary: " + String(value));
                            if (!res->is_class("Resource")) memfree(res);
                            return Error::ERR_FILE_CORRUPT;
                        }
                        Dictionary vdict = value;
                        for (int ki = 0; ki < vdict.size(); ki++) {
                            String key = vdict.keys()[ki];
                            if (vdict[key].get_type() != Variant::DICTIONARY) {
                                UtilityFunctions::push_error("\\V entry is not a Dictionary: " + String(vdict[key]));
                                if (!res->is_class("Resource")) memfree(res);
                                return Error::ERR_FILE_CORRUPT;
                            }
                            Dictionary intDict = vdict[key];
                            res->set(key, decode_dict(intDict, iointerface, dedup));
                        }
                        return res;
                
                    default:
                        break;
                }
            }
    };
}

#endif