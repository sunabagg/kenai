#include "sky.h"

void sunaba::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Sky>("Sky",
        "new", sol::factories(
            []() { return new sunaba::spatial::Sky(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](sunaba::core::Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}