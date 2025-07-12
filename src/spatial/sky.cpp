#include "sky.h"

void kenai::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Sky>("Sky",
        "new", sol::factories(
            []() { return new kenai::spatial::Sky(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](kenai::core::Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}