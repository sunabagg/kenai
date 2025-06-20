#include "panorama_sky_material.h"

void sunaba::spatial::bindPanoramaSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::PanoramaSkyMaterial>("PanoramaSkyMaterial",
        "new", sol::factories(
            []() { return new sunaba::spatial::PanoramaSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Material>(),
        "energyMultiplier", sol::property(&PanoramaSkyMaterial::getEnergyMultiplier, &PanoramaSkyMaterial::setEnergyMultiplier),
        "filterEnabled", sol::property(&PanoramaSkyMaterial::getFilterEnabled, &PanoramaSkyMaterial::setFilterEnabled),
        "panorama", sol::property(&PanoramaSkyMaterial::getPanorama, &PanoramaSkyMaterial::setPanorama),
        "cast", [](sunaba::core::Resource* instance) {
            return new PanoramaSkyMaterial(godot::Object::cast_to<GodotPanoramaSkyMaterial>(instance->getResource()));
        }
    );
}