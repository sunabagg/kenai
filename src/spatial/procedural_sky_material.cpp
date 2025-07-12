#include "procedural_sky_material.h"

void kenai::spatial::bindProceduralSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::ProceduralSkyMaterial>("ProceduralSkyMaterial",
        "new", sol::factories(
            []() { return new kenai::spatial::ProceduralSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Material>(),
        "energyMultiplier", sol::property(&ProceduralSkyMaterial::getEnergyMultiplier, &ProceduralSkyMaterial::setEnergyMultiplier),
        "groundBottomColor", sol::property(&ProceduralSkyMaterial::getGroundBottomColor, &ProceduralSkyMaterial::setGroundBottomColor),
        "groundCurve", sol::property(&ProceduralSkyMaterial::getGroundCurve, &ProceduralSkyMaterial::setGroundCurve),
        "groundEnergyMultiplier", sol::property(&ProceduralSkyMaterial::getGroundEnergyMultiplier, &ProceduralSkyMaterial::setGroundEnergyMultiplier),
        "groundHorizonColor", sol::property(&ProceduralSkyMaterial::getGroundHorizonColor, &ProceduralSkyMaterial::setGroundHorizonColor),
        "skyCover", sol::property(&ProceduralSkyMaterial::getSkyCover, &ProceduralSkyMaterial::setSkyCover),
        "skyCoverModulate", sol::property(&ProceduralSkyMaterial::getSkyCoverModulate, &ProceduralSkyMaterial::setSkyCoverModulate),
        "skyCurve", sol::property(&ProceduralSkyMaterial::getSkyCurve, &ProceduralSkyMaterial::setSkyCurve),
        "skyEnergyMultiplier", sol::property(&ProceduralSkyMaterial::getSkyEnergyMultiplier, &ProceduralSkyMaterial::setSkyEnergyMultiplier),
        "skyHorizonColor", sol::property(&ProceduralSkyMaterial::getSkyHorizonColor, &ProceduralSkyMaterial::setSkyHorizonColor),
        "skyTopColor", sol::property(&ProceduralSkyMaterial::getSkyTopColor, &ProceduralSkyMaterial::setSkyTopColor),
        "sunAngleMax", sol::property(&ProceduralSkyMaterial::getSunAngleMax, &ProceduralSkyMaterial::setSunAngleMax),
        "sunCurve", sol::property(&ProceduralSkyMaterial::getSunCurve, &ProceduralSkyMaterial::setSunCurve),
        "useDebanding", sol::property(&ProceduralSkyMaterial::getUseDebanding, &ProceduralSkyMaterial::setUseDebanding),
        "cast", [](kenai::core::Resource* instance) {
            return new ProceduralSkyMaterial(godot::Object::cast_to<GodotProceduralSkyMaterial>(instance->getResource()));
        }
    );
}