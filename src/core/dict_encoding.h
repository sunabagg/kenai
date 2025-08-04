#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

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
        public:
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

            static Error _filter_resource(const String& rpath) {
                if (!ResourceLoader::get_singleton()->exists(rpath, "Resource")) {
                    return Error::ERR_FILE_NOT_FOUND;
                }
                return Error::OK;
            }

            static Dictionary encode_dict(const Variant& value, Array dedup = Array(), bool recursed = false) {
                auto type = value.get_type();
                Dictionary dict;
                dict["\\T"] = value.get_type_name(type);
                auto pos = dedup.find(value);
                if (pos != -1) {
                    dict["\\R"] = pos;
                    return dict;
                }
                switch (type)
                {
                    case Variant::OBJECT:
                        Object* obj = value;
                        dedup.push_back(obj);
                        if (recursed && obj->is_class("Resource")) {
                            Ref<Resource> res = Ref<Resource>(
                                Object::cast_to<Resource>(
                                    obj
                                )
                            );
                            if (!res->get_path().is_empty() && ResourceLoader::get_singleton()->exists(res->get_path())) {
                                dict["\\P"] = res->get_path();
                                return dict;
                            }
                            dict["\\V"] = Dictionary();
                            const TypedArray<Dictionary>& property_list = obj->get_property_list();
                            for (int p = 0; p < property_list.size(); p++ ) {
                                const Dictionary& prop = property_list[p];
                                String pn = prop["name"];
                                if (pn == "script") continue;
                                if (!prop["usage"] && PROPERTY_USAGE_STORAGE) continue;
                                dict["\\V"] = encode_dict(obj->get(pn), dedup, true);
                            }
                        }
                    
                    case Variant::ARRAY:
                        Array arr = value;
                        Array outArr;
                        auto err = outArr.resize(arr.size());
                        if (err != Error::OK) {
                            UtilityFunctions::push_error("Cannot allocate array");
                            return Dictionary();
                        }
                        for (int i = 0; i < arr.size(); i++) {
                            outArr[i] = encode_dict(arr[i], dedup, true);
                        }
                        dict["\\AT"] = Variant::get_type_name(static_cast<Variant::Type>(arr.get_typed_builtin()));
                        dict["\\AC"] = arr.get_typed_class_name();
                        dict["\\V"] = outArr; 
                
                    case Variant::DICTIONARY:
                        Dictionary dic = value;
                        Dictionary outDic;
                        for (int ki = 0; ki < dic.size(); ki++)
                        {
                            Variant k = dic.keys()[ki];
                            outDic[k] = encode_dict(dic[k], dedup, true);
                        }
                        dic["\\KT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_key_builtin()));
                        dic["\\VT"] = Variant::get_type_name(static_cast<Variant::Type>(dic.get_typed_value_builtin()));
                        dic["\\VC"] = dic.get_typed_value_class_name();
                        dic["\\V"] = outDic;
                        
                    default:
                        dic["\\V"] = value;
                }
                return dict;
            }
    };
}

#endif