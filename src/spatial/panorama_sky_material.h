#ifndef PANORAMA_SKY_MATERIAL_H
#define PANORAMA_SKY_MATERIAL_H

#include <godot_cpp/classes/panorama_sky_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPanoramaSkyMaterial godot::PanoramaSkyMaterial

#include "../core/material.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial {
    void bindPanoramaSkyMaterial(sol::state_view& lua);

    class PanoramaSkyMaterial : public sunaba::core::Material {
    private:
        GodotPanoramaSkyMaterial* material = nullptr;
    public:
        PanoramaSkyMaterial(GodotPanoramaSkyMaterial* m) {
            setPanoramaSkyMaterial(m);
        }

        PanoramaSkyMaterial() {
            setPanoramaSkyMaterial(memnew(GodotPanoramaSkyMaterial));
        }

        GodotPanoramaSkyMaterial* getPanoramaSkyMaterial() {
            return material;
        }

        void setPanoramaSkyMaterial(GodotPanoramaSkyMaterial* m) {
            material = m;
            //material->reference();
            setMaterial(material);
        }

        float getEnergyMultiplier() {
            return material->get_energy_multiplier();
        }

        void setEnergyMultiplier(float multiplier) {
            material->set_energy_multiplier(multiplier);
        }

        bool getFilterEnabled() {
            return material->is_filtering_enabled();
        }

        void setFilterEnabled(bool enable) {
            material->set_filtering_enabled(enable);
        }

        sunaba::core::Texture2D* getPanorama() {
            return new sunaba::core::Texture2D(
                material->get_panorama().ptr()
            );
        }

        void setPanorama(sunaba::core::Texture2D* texture) {
            material->set_panorama(texture->getTexture2D());
        }
    };
}

#endif // PANORAMA_SKY_MATERIAL_H