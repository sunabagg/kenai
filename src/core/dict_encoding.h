#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/classes/shader.hpp>

#include "io/io_interface.h"
#include "image.h"


using namespace godot;

namespace sunaba::core {
    bool convert_variant(Variant &dest, const Variant &src, Variant::Type target_type) {
    if (src.get_type() == target_type) {
        dest = src;
        return true;
    }

    switch (target_type) {
            case Variant::NIL: {
                dest = Variant();
                return true;
            }
            case Variant::INT: {
                if (src.get_type() == Variant::STRING) {
                    dest = String(src).to_int();
                    return true;
                }
                if (src.get_type() == Variant::FLOAT) {
                    dest = (int)(double)src;
                    return true;
                }
                break;
            }
            case Variant::FLOAT: {
                if (src.get_type() == Variant::STRING) {
                    dest = String(src).to_float();
                    return true;
                }
                if (src.get_type() == Variant::INT) {
                    dest = (double)(int)src;
                    return true;
                }
                break;
            }
            case Variant::STRING: {
                dest = src.stringify();
                return true;
            }
            default:
                break;
        }

        return false; // Conversion not supported
    }

    class DictEncoding {
        protected:

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

            static bool dicHas(Dictionary dic, const String& v) {
                for (int i = 0; i < dic.size(); i++) {
                    String key = dic.keys()[i];
                    if (key == v)
                        return true;
                }
                    
                return false;
            }
    
        public:
            static bool isImagePath(const String& path) {
                if (path.ends_with(".png"))
                    return true;
                else if (path.ends_with(".jpg"))
                    return true;
                else if (path.ends_with(".jpeg"))
                    return true;
                else if (path.ends_with(".webp"))
                    return true;
                else if (path.ends_with(".tga"))
                    return true;
                else if (path.ends_with(".bmp"))
                    return true;
                else if (path.ends_with(".svg"))
                    return true;
                else if (path.ends_with(".ktx"))
                    return true;
                else 
                    return false;
            }

            static Dictionary encode_dict(const Variant& value, io::IoInterface* iointeface, Array dedup = Array(), bool recursed = false) {
                auto type = value.get_type();
                Dictionary dict;
                dict["$T"] = value.get_type_name(type);
                auto pos = dedup.find(value);
                if (pos != -1) {
                    dict["$R"] = pos;
                    return dict;
                }
                // Declare variables outside the switch to avoid bypassing initialization
                Object* obj = nullptr;
                Ref<godot::Resource> res;
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
                        dict["$C"] = obj->get_class();
                        dedup.push_back(obj);
                        if (recursed && obj->is_class("Resource")) {
                            res = Ref<godot::Resource>(
                                Object::cast_to<godot::Resource>(
                                    obj
                                )
                            );
                            if (!res->get_path().is_empty() && iointeface->fileExists(res->get_path().utf8().get_data())) {
                                dict["$P"] = res->get_path();
                                return dict;
                            }
                            Dictionary valDict = Dictionary();
                            dict["$V"] = valDict;
                            property_list = obj->get_property_list();
                            for (int p = 0; p < property_list.size(); p++ ) {
                                const Dictionary& prop = property_list[p];
                                //UtilityFunctions::print(prop);
                                String pn = prop["name"];
                                if (pn == "script") continue;
                                if (!prop["usage"] && PROPERTY_USAGE_STORAGE) continue;
                                valDict[pn] = encode_dict(obj->get(pn), iointeface, dedup, true);
                                //UtilityFunctions::print(dict);
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
                        dict["$AT"] = Variant::get_type_name(static_cast<Variant::Type>(arr.get_typed_builtin()));
                        dict["$AC"] = arr.get_typed_class_name();
                        dict["$V"] = outArr; 
                        break;
                
                    case Variant::DICTIONARY:
                        dic = value;
                        outDic = Dictionary();
                        for (int ki = 0; ki < dic.size(); ki++)
                        {
                            Variant k = dic.keys()[ki];
                            outDic[k] = encode_dict(dic[k], iointeface, dedup, true);
                        }
                        dict["$KT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_key_builtin()));
                        dict["$VT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_value_builtin()));
                        dict["$VC"] = dic.get_typed_value_class_name();
                        dict["$V"] = outDic;
                        break;
                        
                    default:
                        dict["$V"] = value;
                        break;
                }
                return dict;
            }

            static Variant decode_dict(Dictionary dict, io::IoInterface* iointerface, Array dedup = Array()) {
                if (dicHas(dict, "$R")) {
                    int64_t index = dict["$R"];
                    return dedup[index];
                }
                if (!dicHas(dict, "$T")) {
                    UtilityFunctions::push_error("Dictionary does not contain key $T");
                    return Error::ERR_FILE_CORRUPT;
                }
                if (dict["$T"].get_type() != Variant::STRING) {
                    UtilityFunctions::push_error("$T is not a string.");
                    return Error::ERR_FILE_CORRUPT;
                }
                String type = dict["$T"];
                if (!dict.has("$V") && dict.has("$P")) {
                    UtilityFunctions::push_error("Dictionary does not contain key $V");
                    return Error::ERR_FILE_CORRUPT;
                }
                if (!isType(type)) {
                    UtilityFunctions::push_error("Type " + type + " not recognized");
                    return Error::ERR_FILE_CORRUPT;
                }
                int64_t typei64 = typenames()[type];
                Variant::Type typei = static_cast<Variant::Type>(typei64);

                // Declare all variables that are assigned inside the switch before the switch
                Variant cnamev;
                String cname;
                Error ret = Error::OK;
                Object* res = nullptr;
                Variant value;
                Dictionary vdict;
                String key;
                Dictionary intDict;
                Array arr;
                Array outArr;
                Error err = Error::OK;
                Dictionary d;
                Dictionary dic;
                Dictionary outDic;
                Variant::Type kt = Variant::NIL;
                int64_t t_int = 0;
                Variant::Type t = Variant::NIL;
                StringName cn = "";
                StringName vcn = "";
                int64_t kti = 0;
                int64_t vti = 0;

                switch (typei)
                {
                    case Variant::OBJECT:
                        if (!dicHas(dict, "$C")) {
                            UtilityFunctions::push_error("Dictionary does not containe key $C");
                            return Error::ERR_FILE_CORRUPT;
                        }
                        cnamev = dict["$C"];
                        if (cnamev.get_type() != Variant::STRING) {
                            UtilityFunctions::push_error("$C is not a string: " + String(cnamev));
                            return Error::ERR_FILE_CORRUPT;
                        }
                        cname = cnamev;
                        ret = _filter_class(cname);
                        if (ret != Error::OK) 
                            return ret;
                        res = ClassDBSingleton::get_singleton()->instantiate(cname);
                        dedup.push_back(res);
                        if (dicHas(dict, "$P")) {
                            String ppath = dict["$P"];
                            ret = _filter_resource(ppath, iointerface);
                            if (ret != Error::OK) 
                                return ret;
                            if (isImagePath(ppath)) {
                                Image* image = new Image();
                                ret = static_cast<Error>(image->load(iointerface, ppath.utf8().get_data()));
                                if (ret != Error::OK) {
                                    UtilityFunctions::push_error("Invalid Image");
                                    return ret;
                                }
                                return Ref<godot::Image>(image->getImage());
                            }
                            std::string resstr = iointerface->loadText(ppath.utf8().get_data());
                            if (ppath.ends_with(".shdr")) {
                                Ref<godot::Shader> shader = Ref<Shader>(memnew(Shader));
                                shader->set_code(resstr.c_str());
                                return shader;
                            }
                            Variant resjson = JSON::parse_string(resstr.c_str());
                            if (resjson.get_type() != Variant::DICTIONARY) {
                                UtilityFunctions::push_error("JSON did not decode into Dictionary");
                                return Error::ERR_FILE_CORRUPT;
                            }
                            return decode_dict(resjson, iointerface);
                        }
                        value = dict["$V"];
                        if (value.get_type() != Variant::DICTIONARY) {
                            UtilityFunctions::push_error("$V is not a Dictionary: " + String(value));
                            if (!res->is_class("Resource")) memfree(res);
                            return Error::ERR_FILE_CORRUPT;
                        }
                        vdict = value;
                        for (int ki = 0; ki < vdict.size(); ki++) {
                            key = vdict.keys()[ki];
                            if (vdict[key].get_type() != Variant::DICTIONARY) {
                                UtilityFunctions::push_error("$V entry is not a Dictionary: " + String(vdict[key]));
                                if (!res->is_class("Resource")) memfree(res);
                                return Error::ERR_FILE_CORRUPT;
                            }
                            intDict = vdict[key];
                            res->set(key, decode_dict(intDict, iointerface, dedup));
                        }
                        return res;
                
                    case Variant::ARRAY:
                        arr = dict["$V"];
                        if (dicHas(dict, "$AT")) {
                            t_int = typenames()[dict["$AT"]];
                            t = static_cast<Variant::Type>(t_int);
                            cn = "";
                            if (t == Variant::OBJECT) {
                                StringName cname2 = dict["$AC"];
                                ret = _filter_class(cname2);
                                if (ret != Error::OK) {
                                    return ret;
                                }
                                cn = cname2;
                            }
                            outArr = Array();
                        }
                        else  {
                            outArr = Array();
                        }
                        err = static_cast<Error>(outArr.resize(arr.size()));
                        if (err != Error::OK) {
                            UtilityFunctions::push_error("Cannot allocate array");
                            return err;
                        }
                        for (int i = 0; i < arr.size(); i++) {
                            d = arr[i];
                            outArr[i] = decode_dict(d, iointerface, dedup);
                        }
                        return outArr;
                    case Variant::DICTIONARY:
                        dic = dict["$V"];
                        if (dicHas(dict, "$KT")) {
                            kti = typenames()[dict["$KT"]];
                            kt = static_cast<Variant::Type>(kti);
                            if (!dicHas(dict, "$VT")) {
                                UtilityFunctions::push_error("Dictionary does not contain key $VT");
                                return Error::ERR_FILE_CORRUPT;
                            }
                            vti = typenames()[dict["$VT"]];
                            Variant::Type vt = static_cast<Variant::Type>(vti);
                            vcn = "";
                            if (kt == Variant::OBJECT) {
                                UtilityFunctions::push_error("Objects are not supported");
                                return Error::ERR_FILE_CORRUPT;
                            }
                            if (vt == Variant::OBJECT) {
                                StringName cname3 = dict["$VC"];
                                ret = _filter_class(cname3);
                                if (ret != Error::OK) {
                                    return ret;
                                }
                                vcn = cname3;
                            }
                            outDic = Dictionary();
                        }
                        else  {
                            outDic = Dictionary();
                        }
                        for (int ki = 0; ki < dic.size(); ki++) {
                            Variant k = dic.keys()[ki];
                            d = dic[k];
                            if (kt) {
                                Variant nk; 
                                convert_variant(k, kt, kt);
                                outDic[nk] = decode_dict(d, iointerface, dedup);
                            }
                            else {
                                outDic[k] = decode_dict(d, iointerface, dedup);
                            }
                        }
                        return outDic;
                    case Variant::NIL:
                        return Variant();
                    default:
                        Variant newval;
                        convert_variant(newval, dict["$V"], typei);
                        return newval;
                        break;
                }
            }
    };
}

#endif