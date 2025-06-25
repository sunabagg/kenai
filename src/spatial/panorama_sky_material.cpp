#include "panorama_sky_material.h"

void lucidware::spatial::bindPanoramaSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::PanoramaSkyMaterial>("PanoramaSkyMaterial",
        "new", sol::factories(
            []() { return new lucidware::spatial::PanoramaSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Material>(),
        "energyMultiplier", sol::property(&PanoramaSkyMaterial::getEnergyMultiplier, &PanoramaSkyMaterial::setEnergyMultiplier),
        "filterEnabled", sol::property(&PanoramaSkyMaterial::getFilterEnabled, &PanoramaSkyMaterial::setFilterEnabled),
        "panorama", sol::property(&PanoramaSkyMaterial::getPanorama, &PanoramaSkyMaterial::setPanorama),
        "cast", [](lucidware::core::Resource* instance) {
            return new PanoramaSkyMaterial(godot::Object::cast_to<GodotPanoramaSkyMaterial>(instance->getResource()));
        }
    );
}