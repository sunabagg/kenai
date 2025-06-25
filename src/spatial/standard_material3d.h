#ifndef STANDARD_MATERIAL3D_H
#define STANDARD_MATERIAL3D_H

#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStandardMaterial3D godot::StandardMaterial3D

#include "base_material3d.h"

using namespace godot;

namespace lucidfx::spatial {
    void bindStandardMaterial3D(sol::state_view& lua);

    class StandardMaterial3D : public BaseMaterial3D {
    private:
        GodotStandardMaterial3D* material = nullptr;
    public:
        StandardMaterial3D() {
            setStandardMaterial3D(memnew(GodotStandardMaterial3D));
        }

        StandardMaterial3D(GodotStandardMaterial3D* m) {
            setStandardMaterial3D(m);
        }

        GodotStandardMaterial3D* getStandardMaterial3D() {
            return material;
        }

        void setStandardMaterial3D(GodotStandardMaterial3D* m) {
            material = m;
            material->reference();
            setBaseMaterial3D(material);
        }
    };
}

#endif // STANDARD_MATERIAL3D_H