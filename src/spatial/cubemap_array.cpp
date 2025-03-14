#include "cubemap_array.h"

void sunaba::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::CubemapArray>("CubemapArray",
        sol::base_classes, sol::bases<sunaba::core::ImageTextureLayered>(),
        sol::constructors<CubemapArray()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder
    );
}