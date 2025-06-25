#ifndef WORLD3D_H
#define WORLD3D_H

#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotWorld3D godot::World3D

#include "../core/resource.h"
#include "../core/environment.h"
#include "camera_attributes.h"

using namespace godot;

namespace lucidware::spatial {
    void bindWorld3D(sol::state_view& lua);

    class World3D : public lucidware::core::Resource {
    private:
        GodotWorld3D* world = nullptr;
    public:
        World3D() {
            setWorld3D(memnew(GodotWorld3D));
        }

        World3D(GodotWorld3D* w) {
            setWorld3D(w);
        }

        GodotWorld3D* getWorld3D() {
            return world;
        }

        void setWorld3D(GodotWorld3D* w) {
            world = w;
            world->reference();
            setResource(world);
        }

        CameraAttributes* getCameraAttributes() {
            return new CameraAttributes(world->get_camera_attributes().ptr());
        }

        void setCameraAttributes(CameraAttributes* ca) {
            world->set_camera_attributes(ca->getCameraAttributes());
        }

        lucidware::core::Environment* getEnvironment() {
            return new lucidware::core::Environment(world->get_environment().ptr());
        }

        void setEnvironment(lucidware::core::Environment* env) {
            world->set_environment(env->getEnvironment());
        }
    };
}

#endif // WORLD3D_H