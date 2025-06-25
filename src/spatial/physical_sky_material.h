#ifndef PHYSICAL_SKY_MATERIAL_H
#define PHYSICAL_SKY_MATERIAL_H

#include <godot_cpp/classes/physical_sky_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPhysicalSkyMaterial godot::PhysicalSkyMaterial

#include "../core/material.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindPhysicalSkyMaterial(sol::state_view& lua);

    class PhysicalSkyMaterial : public lucidware::core::Material {
    private:
        GodotPhysicalSkyMaterial* material = nullptr;
    public:
        PhysicalSkyMaterial(GodotPhysicalSkyMaterial* m) {
            setPhysicalSkyMaterial(m);
        }

        PhysicalSkyMaterial() {
            setPhysicalSkyMaterial(memnew(GodotPhysicalSkyMaterial));
        }

        GodotPhysicalSkyMaterial* getPhysicalSkyMaterial() {
            return material;
        }

        void setPhysicalSkyMaterial(GodotPhysicalSkyMaterial* m) {
            material = m;
            material->reference();
            setMaterial(material);
        }

        float getEnergyMultiplier() {
            return material->get_energy_multiplier();
        }

        void setEnergyMultiplier(float multiplier) {
            material->set_energy_multiplier(multiplier);
        }

        Color getGroundColor() {
            return material->get_ground_color();
        }

        void setGroundColor(Color color) {
            material->set_ground_color(color);
        }

        float getMieCoefficient() {
            return material->get_mie_coefficient();
        }

        void setMieCoefficient(float coefficient) {
            material->set_mie_coefficient(coefficient);
        }

        Color getMieColor() {
            return material->get_mie_color();
        }

        void setMieColor(Color color) {
            material->set_mie_color(color);
        }

        float getMieEccentricity() {
            return material->get_mie_eccentricity();
        }

        void setMieEccentricity(float eccentricity) {
            material->set_mie_eccentricity(eccentricity);
        }

        lucidware::core::Texture2D* getNightSky() {
            return new lucidware::core::Texture2D(
                material->get_night_sky().ptr()
            );
        }

        void setNightSky(lucidware::core::Texture2D* texture) {
            material->set_night_sky(texture->getTexture2D());
        }

        float getRayleighCoefficient() {
            return material->get_rayleigh_coefficient();
        }

        void setRayleighCoefficient(float coefficient) {
            material->set_rayleigh_coefficient(coefficient);
        }

        Color getRayleighColor() {
            return material->get_rayleigh_color();
        }

        void setRayleighColor(Color color) {
            material->set_rayleigh_color(color);
        }

        float getSunDiskScale() {
            return material->get_sun_disk_scale();
        }

        void setSunDiskScale(float scale) {
            material->set_sun_disk_scale(scale);
        }

        float getTurbidity() {
            return material->get_turbidity();
        }

        void setTurbidity(float turbidity) {
            material->set_turbidity(turbidity);
        }

        bool getUseDebanding() {
            return material->get_use_debanding();
        }

        void setUseDebanding(bool enable) {
            material->set_use_debanding(enable);
        }
    };
}

#endif // PHYSICAL_SKY_MATERIAL_H