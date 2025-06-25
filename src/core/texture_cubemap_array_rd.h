#ifndef TEXTURE_LAYERED_ARRAY_RD_H
#define TEXTURE_LAYERED_ARRAY_RD_H

#include <godot_cpp/classes/texture_cubemap_array_rd.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTextureCubemapArrayRD godot::TextureCubemapArrayRD

#include "texture_layered_rd.h"

using namespace godot;

namespace lucidware::core {
    void bindTextureCubemapArrayRD(sol::state &lua);

    class TextureCubemapArrayRD : public TextureLayeredRD {
    private:
        GodotTextureCubemapArrayRD* textureCubemapArrayRD = nullptr; // Pointer to the TextureCubemapArrayRD instance
    public:
        // Constructor with Ref<GodotTextureCubemapArrayRD> parameter
        TextureCubemapArrayRD(GodotTextureCubemapArrayRD* textureCubemapArrayRD) {
            setTextureCubemapArrayRD(textureCubemapArrayRD);
        }

        // Constructor with no parameters
        TextureCubemapArrayRD() {
            setTextureCubemapArrayRD(memnew(GodotTextureCubemapArrayRD));
        }

        // Getter for the TextureCubemapArrayRD node
        GodotTextureCubemapArrayRD* getTextureCubemapArrayRD() {
            return textureCubemapArrayRD;
        }

        // Setter for the TextureCubemapArrayRD node
        void setTextureCubemapArrayRD(GodotTextureCubemapArrayRD* textureCubemapArrayRD) {
            this->textureCubemapArrayRD = textureCubemapArrayRD;
            textureCubemapArrayRD->reference();
            setTextureLayeredRD(textureCubemapArrayRD);
        }
    };  
}

#endif // TEXTURE_LAYERED_ARRAY_RD_H