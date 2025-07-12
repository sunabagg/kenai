#include "panorama_sky_material.h"

void kenai::spatial::bindPanoramaSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::PanoramaSkyMaterial>("PanoramaSkyMaterial",
        "new", sol::factories(
            []() { return new kenai::spatial::PanoramaSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Material>(),
        "energyMultiplier", sol::property(&PanoramaSkyMaterial::getEnergyMultiplier, &PanoramaSkyMaterial::setEnergyMultiplier),
        "filterEnabled", sol::property(&PanoramaSkyMaterial::getFilterEnabled, &PanoramaSkyMaterial::setFilterEnabled),
        "panorama", sol::property(&PanoramaSkyMaterial::getPanorama, &PanoramaSkyMaterial::setPanorama),
        "cast", [](kenai::core::Resource* instance) {
            return new PanoramaSkyMaterial(godot::Object::cast_to<GodotPanoramaSkyMaterial>(instance->getResource()));
        }
    );
}