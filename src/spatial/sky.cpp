#include "sky.h"

void lucidfx::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Sky>("Sky",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Sky(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](lucidfx::core::Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}