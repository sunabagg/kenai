#ifndef FOG_MATERIAL_H
#define FOG_MATERIAL_H

#include <godot_cpp/classes/fog_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotFogMaterial godot::FogMaterial

#include "../core/material.h"
#include "../core/convert_godot_lua.h"



using namespace godot;

namespace lucidfx::spatial {
    void bindFogMaterial(sol::state_view& lua);

    class FogMaterial : public lucidfx::core::Material {
    private:
        GodotFogMaterial* fogMaterial;
    public:

        FogMaterial(GodotFogMaterial* material) {
            setFogMaterial(material);
        }

        FogMaterial() {
            setFogMaterial(memnew(GodotFogMaterial));
        }

        GodotFogMaterial* getFogMaterial() {
            return fogMaterial;
        }

        void setFogMaterial(GodotFogMaterial* m) {
            fogMaterial = m;
            fogMaterial->reference();
            setMaterial(fogMaterial);
        }

        Color getAlbedo() {
            return fogMaterial->get_albedo();
        }

        void setAlbedo(Color albedo) {
            fogMaterial->set_albedo(albedo);
        }

        float getDensity() {
            return fogMaterial->get_density();
        }

        void setDensity(float density) {
            fogMaterial->set_density(density);
        }

        float getEdgeFade() {
            return fogMaterial->get_edge_fade();
        }

        void setEdgeFade(float edgeFade) {
            fogMaterial->set_edge_fade(edgeFade);
        }

        Color getEmission() {
            return fogMaterial->get_emission();
        }

        void setEmission(Color emission) {
            fogMaterial->set_emission(emission);
        }

        float getHeightFalloff() {
            return fogMaterial->get_height_falloff();
        }

        void setHeightFalloff(float heightFalloff) {
            fogMaterial->set_height_falloff(heightFalloff);
        }
    };
}
#endif