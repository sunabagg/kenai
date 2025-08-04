#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

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
                //if (!_glob_filters(cname))
                if (!ClassDBSingleton::get_singleton()->class_exists(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                if (!ClassDBSingleton::get_singleton()->can_instantiate(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                return Error::OK;
            }
    };
}

#endif