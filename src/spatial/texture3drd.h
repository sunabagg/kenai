#ifndef TEXTURE3DRD_H
#define TEXTURE3DRD_H

#include <godot_cpp/classes/texture3drd.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTexture3DRD godot::Texture3DRD

#include "texture3d.h"

using namespace godot;

#define Texture3D lucidfx::spatial::Texture3D

namespace lucidfx::spatial {
    void bindTexture3DRD(sol::state_view& lua);

    class Texture3DRD : public Texture3D {
    private:
        GodotTexture3DRD* texture = nullptr;
    public:
        Texture3DRD() {
            setTexture3DRD(memnew(GodotTexture3DRD));
        }

        Texture3DRD(GodotTexture3DRD* t) {
            setTexture3DRD(t);
        }

        GodotTexture3DRD* getTexture3DRD() {
            return texture;
        }

        void setTexture3DRD(GodotTexture3DRD* t) {
            texture = t;
            texture->reference();
            setTexture3D(texture);
        }
    };
}

#endif // TEXTURE3DRD_H