#ifndef TEXTURE_LAYERED_RD_H
#define TEXTURE_LAYERED_RD_H

#include <godot_cpp/classes/texture_layered_rd.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTextureLayeredRD godot::TextureLayeredRD

#include "texture_layered.h"

using namespace godot;

namespace lucidware::core {
    void bindTextureLayeredRD(sol::state &lua);

    class TextureLayeredRD : public TextureLayered {
    private:
        GodotTextureLayeredRD* textureLayeredRD = nullptr; // Pointer to the TextureLayeredRD instance
    public:
        // Constructor with Ref<GodotTextureLayeredRD> parameter
        TextureLayeredRD(GodotTextureLayeredRD* textureLayeredRD) {
            setTextureLayeredRD(textureLayeredRD);
        }

        // Constructor with no parameters
        TextureLayeredRD() {
            setTextureLayeredRD(memnew(GodotTextureLayeredRD));
        }

        // Getter for the TextureLayeredRD node
        GodotTextureLayeredRD* getTextureLayeredRD() {
            return textureLayeredRD;
        }

        // Setter for the TextureLayeredRD node
        void setTextureLayeredRD(GodotTextureLayeredRD* textureLayeredRD) {
            this->textureLayeredRD = textureLayeredRD;
            textureLayeredRD->reference();
            setTextureLayered(textureLayeredRD);
        }
    };
    
}

#endif // TEXTURE_LAYERED_RD_H