#include "panorama_sky_material.h"

void lucidfx::spatial::bindPanoramaSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::PanoramaSkyMaterial>("PanoramaSkyMaterial",
        "new", sol::factories(
            []() { return new lucidfx::spatial::PanoramaSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Material>(),
        "energyMultiplier", sol::property(&PanoramaSkyMaterial::getEnergyMultiplier, &PanoramaSkyMaterial::setEnergyMultiplier),
        "filterEnabled", sol::property(&PanoramaSkyMaterial::getFilterEnabled, &PanoramaSkyMaterial::setFilterEnabled),
        "panorama", sol::property(&PanoramaSkyMaterial::getPanorama, &PanoramaSkyMaterial::setPanorama),
        "cast", [](lucidfx::core::Resource* instance) {
            return new PanoramaSkyMaterial(godot::Object::cast_to<GodotPanoramaSkyMaterial>(instance->getResource()));
        }
    );
}