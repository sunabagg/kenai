#include "texture_layered_rd.h"

void sunaba::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<sunaba::core::TextureLayeredRD>("TextureLayeredRD",
        sol::constructors<sunaba::core::TextureLayeredRD()>(),
        sol::base_classes, sol::bases<sunaba::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(static_cast<GodotTextureLayeredRD*>(instance->getResource()));
        }
    );
}