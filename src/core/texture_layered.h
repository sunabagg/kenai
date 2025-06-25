#ifndef TEXTURE_LAYERED_H
#define TEXTURE_LAYERED_H

#include <godot_cpp/classes/texture_layered.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTextureLayered godot::TextureLayered

#include "texture.h"
#include "image.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindTextureLayered(sol::state &lua);

    class TextureLayered : public Texture {
    private:
        GodotTextureLayered* textureLayered = nullptr; // Pointer to the TextureLayered instance
    public:
        // Constructor with Ref<GodotTextureLayered> parameter
        TextureLayered(GodotTextureLayered* textureLayered) {
            setTextureLayered(textureLayered);
        }

        // Constructor with no parameters
        TextureLayered() {
            setTextureLayered(memnew(GodotTextureLayered));
        }

        // Getter for the TextureLayered node
        GodotTextureLayered* getTextureLayered() {
            return textureLayered;
        }

        // Setter for the TextureLayered node
        void setTextureLayered(GodotTextureLayered* textureLayered) {
            this->textureLayered = textureLayered;
            textureLayered->reference();
            setTexture(textureLayered);
        }

        int getFormat() {
            return textureLayered->get_format();
        }

        int getHeight() {
            return textureLayered->get_height();
        }

        Image* getLayerData(int layer) {
            return new Image(textureLayered->get_layer_data(layer).ptr());
        }

        int getLayeredType() {
            return textureLayered->get_layered_type();
        }

        int getLayers() {
            return textureLayered->get_layers();
        }

        int getWidth() {
            return textureLayered->get_width();
        }

        bool hasMipmaps() {
            return textureLayered->has_mipmaps();
        }
    };
}

#endif // TEXTURE_LAYERED_H