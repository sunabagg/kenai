#include "noise.h"

void lucidware::core::bindNoise(sol::state_view& lua) {
        lua.new_usertype<Noise>("Noise",
            "new", sol::factories(
                []() { return new Noise(); }
            ),
            sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
            "getImage", &Noise::getImage,
            "getImage3d", &Noise::getImage3d,
            "getNoise1d", &Noise::getNoise1d,
            "getNoise2d", &Noise::getNoise2d,
            "getNoise3d", &Noise::getNoise3d,
            "getSeamlessImage", &Noise::getSeamlessImage,
            "getSeamlessImage3d", &Noise::getSeamlessImage3d,
            "cast", [](Resource* instance) {
                return new Noise(godot::Object::cast_to<GodotNoise>(instance->getResource()));
            }
    );
}