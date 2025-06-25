#ifndef TEXTURE_2D_RD_H
#define TEXTURE_2D_RD_H

#include <godot_cpp/classes/texture2drd.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTexture2DRD godot::Texture2DRD

#include "texture2d.h"

using namespace godot;

namespace lucidware::core {
    void bindTexture2DRD(sol::state &lua);

    class Texture2DRD : public Texture2D {
    private:
        GodotTexture2DRD* texture2dRD = nullptr; // Pointer to the Texture2DRD instance
    public:
        // Constructor with Ref<GodotTexture2DRD> parameter
        Texture2DRD(GodotTexture2DRD* texture2dRD) {
            setTexture2DRD(texture2dRD);
        }

        // Constructor with no parameters
        Texture2DRD() {
            setTexture2DRD(memnew(GodotTexture2DRD));
        }

        // Getter for the Texture2DRD node
        GodotTexture2DRD* getTexture2DRD() {
            return texture2dRD;
        }

        // Setter for the Texture2DRD node
        void setTexture2DRD(GodotTexture2DRD* texture2dRD) {
            this->texture2dRD = texture2dRD;
            texture2dRD->reference();
            setTexture2D(texture2dRD);
        }
    };
}

#endif // TEXTURE_2D_RD_H