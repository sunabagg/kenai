#include "physical_sky_material.h"

void lucidware::spatial::bindPhysicalSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::PhysicalSkyMaterial>("PhysicalSkyMaterial",
        "new", sol::factories(
            []() { return new lucidware::spatial::PhysicalSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Material>(),
        "energyMultiplier", sol::property(&PhysicalSkyMaterial::getEnergyMultiplier, &PhysicalSkyMaterial::setEnergyMultiplier),
        "groundColor", sol::property(&PhysicalSkyMaterial::getGroundColor, &PhysicalSkyMaterial::setGroundColor),
        "mieCoefficient", sol::property(&PhysicalSkyMaterial::getMieCoefficient, &PhysicalSkyMaterial::setMieCoefficient),
        "mieColor", sol::property(&PhysicalSkyMaterial::getMieColor, &PhysicalSkyMaterial::setMieColor),
        "mieEccentricity", sol::property(&PhysicalSkyMaterial::getMieEccentricity, &PhysicalSkyMaterial::setMieEccentricity),
        "nightSky", sol::property(&PhysicalSkyMaterial::getNightSky, &PhysicalSkyMaterial::setNightSky),
        "rayleighCoefficient", sol::property(&PhysicalSkyMaterial::getRayleighCoefficient, &PhysicalSkyMaterial::setRayleighCoefficient),
        "rayleighColor", sol::property(&PhysicalSkyMaterial::getRayleighColor, &PhysicalSkyMaterial::setRayleighColor),
        "sunDiskScale", sol::property(&PhysicalSkyMaterial::getSunDiskScale, &PhysicalSkyMaterial::setSunDiskScale),
        "turbidity", sol::property(&PhysicalSkyMaterial::getTurbidity, &PhysicalSkyMaterial::setTurbidity),
        "useDebanding", sol::property(&PhysicalSkyMaterial::getUseDebanding, &PhysicalSkyMaterial::setUseDebanding),
        "cast", [](lucidware::core::Resource* instance) {
            return new PhysicalSkyMaterial(godot::Object::cast_to<GodotPhysicalSkyMaterial>(instance->getResource()));
        }
    );
}