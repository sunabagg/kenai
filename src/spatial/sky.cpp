#include "sky.h"

void lucidware::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::Sky>("Sky",
        "new", sol::factories(
            []() { return new lucidware::spatial::Sky(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](lucidware::core::Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}