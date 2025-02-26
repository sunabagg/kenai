#include "texture.h"

void sunaba::core::bindTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::Texture>("Texture",
        sol::constructors<sunaba::core::Texture()>(),
        sol::base_classes, sol::bases<sunaba::core::Resource>()
    );
}