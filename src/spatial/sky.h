#ifndef SKY_H
#define SKY_H

#include <godot_cpp/classes/sky.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSky godot::Sky

#include "../core/resource.h"
#include "../core/material.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial {
    void bindSky(sol::state_view& lua);

    class Sky : public lucidfx::core::Resource {
    private:
        GodotSky* sky = nullptr;
    public:
        Sky() {
            setSky(memnew(GodotSky));
        }

        Sky(GodotSky* s) {
            setSky(s);
        }

        GodotSky* getSky() {
            return sky;
        }

        void setSky(GodotSky* s) {
            sky = s;
            sky->reference();
            setResource(sky);
        }

        int getProcessMode() {
            return sky->get_process_mode();
        }

        void setProcessMode(int mode) {
            sky->set_process_mode(static_cast<GodotSky::ProcessMode>(mode));
        }

        int getRadianceSize() {
            return sky->get_radiance_size();
        }

        void setRadianceSize(int size) {
            sky->set_radiance_size(static_cast<GodotSky::RadianceSize>(size));
        }

        lucidfx::core::Material* getSkyMaterial() {
            return new lucidfx::core::Material(sky->get_material().ptr());
        }

        void setSkyMaterial(lucidfx::core::Material* material) {
            sky->set_material(material->getMaterial());
        }
    };
}

#endif // SKY_H
