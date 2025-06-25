#ifndef PROCEDURAL_SKY_MATERIAL_H
#define PROCEDURAL_SKY_MATERIAL_H

#include <godot_cpp/classes/procedural_sky_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotProceduralSkyMaterial godot::ProceduralSkyMaterial

#include "../core/material.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindProceduralSkyMaterial(sol::state_view& lua);

    class ProceduralSkyMaterial : public lucidware::core::Material {
    private:
        GodotProceduralSkyMaterial* proceduralSkyMaterial;
    public:

        ProceduralSkyMaterial(GodotProceduralSkyMaterial* material) {
            setProceduralSkyMaterial(material);
        }

        ProceduralSkyMaterial() {
            setProceduralSkyMaterial(memnew(GodotProceduralSkyMaterial));
        }

        GodotProceduralSkyMaterial* getProceduralSkyMaterial() {
            return proceduralSkyMaterial;
        }

        void setProceduralSkyMaterial(GodotProceduralSkyMaterial* m) {
            proceduralSkyMaterial = m;
            proceduralSkyMaterial->reference();
            setMaterial(proceduralSkyMaterial);
        }

        float getEnergyMultiplier() {
            return proceduralSkyMaterial->get_energy_multiplier();
        }

        void setEnergyMultiplier(float energy) {
            proceduralSkyMaterial->set_energy_multiplier(energy);
        }

        Color getGroundBottomColor() {
            return proceduralSkyMaterial->get_ground_bottom_color();
        }

        void setGroundBottomColor(Color color) {
            proceduralSkyMaterial->set_ground_bottom_color(color);
        }

        float getGroundCurve() {
            return proceduralSkyMaterial->get_ground_curve();
        }

        void setGroundCurve(float curve) {
            proceduralSkyMaterial->set_ground_curve(curve);
        }

        float getGroundEnergyMultiplier() {
            return proceduralSkyMaterial->get_ground_energy_multiplier();
        }

        void setGroundEnergyMultiplier(float energy) {
            proceduralSkyMaterial->set_ground_energy_multiplier(energy);
        }

        Color getGroundHorizonColor() {
            return proceduralSkyMaterial->get_ground_horizon_color();
        }

        void setGroundHorizonColor(Color color) {
            proceduralSkyMaterial->set_ground_horizon_color(color);
        }

        lucidware::core::Texture2D* getSkyCover() {
            return new lucidware::core::Texture2D(
                proceduralSkyMaterial->get_sky_cover().ptr()
            );
        }

        void setSkyCover(lucidware::core::Texture2D* texture) {
            proceduralSkyMaterial->set_sky_cover(texture->getTexture2D());
        }

        Color getSkyCoverModulate() {
            return proceduralSkyMaterial->get_sky_cover_modulate();
        }

        void setSkyCoverModulate(Color color) {
            proceduralSkyMaterial->set_sky_cover_modulate(color);
        }

        float getSkyCurve() {
            return proceduralSkyMaterial->get_sky_curve();
        }

        void setSkyCurve(float curve) {
            proceduralSkyMaterial->set_sky_curve(curve);
        }

        float getSkyEnergyMultiplier() {
            return proceduralSkyMaterial->get_sky_energy_multiplier();
        }

        void setSkyEnergyMultiplier(float energy) {
            proceduralSkyMaterial->set_sky_energy_multiplier(energy);
        }

        Color getSkyHorizonColor() {
            return proceduralSkyMaterial->get_sky_horizon_color();
        }

        void setSkyHorizonColor(Color color) {
            proceduralSkyMaterial->set_sky_horizon_color(color);
        }

        Color getSkyTopColor() {
            return proceduralSkyMaterial->get_sky_top_color();
        }

        void setSkyTopColor(Color color) {
            proceduralSkyMaterial->set_sky_top_color(color);
        }

        float getSunAngleMax() {
            return proceduralSkyMaterial->get_sun_angle_max();
        }

        void setSunAngleMax(float angle) {
            proceduralSkyMaterial->set_sun_angle_max(angle);
        }

        float getSunCurve() {
            return proceduralSkyMaterial->get_sun_curve();
        }

        void setSunCurve(float curve) {
            proceduralSkyMaterial->set_sun_curve(curve);
        }

        bool getUseDebanding() {
            return proceduralSkyMaterial->get_use_debanding();
        }

        void setUseDebanding(bool enable) {
            proceduralSkyMaterial->set_use_debanding(enable);
        }
    };
}

#endif // PROCEDURAL_SKY_MATERIAL_H