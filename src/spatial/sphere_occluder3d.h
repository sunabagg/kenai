#ifndef SPHERE_OCCLUDER3D_H
#define SPHERE_OCCLUDER3D_H

#include <godot_cpp/classes/sphere_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSphereOccluder3D godot::SphereOccluder3D

#include "occluder3d.h"

using namespace godot;

namespace lucidware::spatial {
    void bindSphereOccluder3D(sol::state_view& lua);

    class SphereOccluder3D : public Occluder3D {
    private:
        GodotSphereOccluder3D* sphere_occluder = nullptr;
    public:
        SphereOccluder3D() {
            setSphereOccluder3D(memnew(GodotSphereOccluder3D));
        }

        SphereOccluder3D(GodotSphereOccluder3D* o) {
            setSphereOccluder3D(o);
        }

        GodotSphereOccluder3D* getSphereOccluder3D() {
            return sphere_occluder;
        }

        void setSphereOccluder3D(GodotSphereOccluder3D* o) {
            sphere_occluder = o;
            sphere_occluder->reference();
            setResource(sphere_occluder);
        }

        float getRadius() {
            return sphere_occluder->get_radius();
        }

        void setRadius(float radius) {
            sphere_occluder->set_radius(radius);
        }
    };
}

#endif // SPHERE_OCCLUDER3D_H