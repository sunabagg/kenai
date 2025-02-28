#include "texture_cubemap_rd.h"

void sunaba::core::bindTexturedCubemapRD(sol::state &lua) {
    lua.new_usertype<sunaba::core::TexturedCubemapRD>("TexturedCubemapRD",
        sol::constructors<sunaba::core::TexturedCubemapRD()>(),
        sol::base_classes, sol::bases<sunaba::core::TextureCubemapRD>(),
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "getFlags", &sunaba::core::TexturedCubemapRD::getFlags,
        "cast", [](Resource* instance) {
            return new TexturedCubemapRD(static_cast<GodotTexturedCubemapRD*>(instance->getResource()));
        }
    );
}