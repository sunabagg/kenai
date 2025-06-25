#ifndef TEXTURE_CUBEMAP_RD_H
#define TEXTURE_CUBEMAP_RD_H

#include <godot_cpp/classes/texture_cubemap_rd.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTextureCubemapRD godot::TextureCubemapRD

#include "texture_layered_rd.h"

using namespace godot;

namespace lucidfx::core {
    void bindTextureCubemapRD(sol::state &lua);

    class TextureCubemapRD : public TextureLayeredRD {
    private:
        GodotTextureCubemapRD* textureCubemapRD = nullptr; // Pointer to the TextureCubemapRD instance
    public:
        // Constructor with Ref<GodotTextureCubemapRD> parameter
        TextureCubemapRD(GodotTextureCubemapRD* textureCubemapRD) {
            setTextureCubemapRD(textureCubemapRD);
        }

        // Constructor with no parameters
        TextureCubemapRD() {
            setTextureCubemapRD(memnew(GodotTextureCubemapRD));
        }

        // Getter for the TextureCubemapRD node
        GodotTextureCubemapRD* getTextureCubemapRD() {
            return textureCubemapRD;
        }

        // Setter for the TextureCubemapRD node
        void setTextureCubemapRD(GodotTextureCubemapRD* textureCubemapRD) {
            this->textureCubemapRD = textureCubemapRD;
            textureCubemapRD->reference();
            setTextureLayeredRD(textureCubemapRD);
        }
    };  
}
#endif // TEXTURE_CUBEMAP_RD_H