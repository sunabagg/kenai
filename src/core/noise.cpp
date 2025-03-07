#include "noise.h"

void sunaba::core::bindNoise(sol::state_view& lua) {
        lua.new_usertype<Noise>("Noise",
            sol::constructors<Noise(), Noise(GodotNoise*)>(),
            sol::base_classes, sol::bases<sunaba::core::Resource>(),
            "getImage", &Noise::getImage,
            "getImage3d", &Noise::getImage3d,
            "getNoise1d", &Noise::getNoise1d,
            "getNoise2d", &Noise::getNoise2d,
            "getNoise3d", &Noise::getNoise3d,
            "getSeamlessImage", &Noise::getSeamlessImage,
            "getSeamlessImage3d", &Noise::getSeamlessImage3d
    );
}