#include "fog_material.h"

void sunaba::spatial::bindFogMaterial(sol::state_view &lua) {
    lua.new_usertype<FogMaterial>("FogMaterial",
        "new", sol::factories(
            []() { return new FogMaterial(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Material>(),
        "albedo", sol::property(&FogMaterial::getAlbedo, &FogMaterial::setAlbedo),
        "density", sol::property(&FogMaterial::getDensity, &FogMaterial::setDensity),
        "edgeFade", sol::property(&FogMaterial::getEdgeFade, &FogMaterial::setEdgeFade));
}