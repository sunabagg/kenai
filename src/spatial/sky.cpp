#include "sky.h"

void sunaba::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Sky>("Sky",
        sol::constructors<Sky()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}