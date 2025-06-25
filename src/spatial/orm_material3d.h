#ifndef ORM_MATERIAL3D_H
#define ORM_MATERIAL3D_H

#include <godot_cpp/classes/orm_material3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotOrmMaterial3D godot::ORMMaterial3D

#include "base_material3d.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindOrmMaterial3D(sol::state_view& lua);

    class OrmMaterial3D : public lucidware::spatial::BaseMaterial3D {
    private:
        GodotOrmMaterial3D* material = nullptr;
    public:
        OrmMaterial3D(GodotOrmMaterial3D* m) {
            setOrmMaterial(m);
        }

        OrmMaterial3D() {
            setOrmMaterial(memnew(GodotOrmMaterial3D));
        }

        GodotOrmMaterial3D* getOrmMaterial() {
            return material;
        }

        void setOrmMaterial(GodotOrmMaterial3D* m) {
            material = m;
            material->reference();
            setBaseMaterial3D(material);
        }
    };
}

#endif // ORM_MATERIAL3D_H