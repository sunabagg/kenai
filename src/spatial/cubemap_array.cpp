#include "cubemap_array.h"

void sunaba::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::CubemapArray>("CubemapArray",
        sol::constructors<CubemapArray()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder,
        "cast", [](sunaba::core::Resource* instance) {
            return new CubemapArray(godot::Object::cast_to<GodotCubemapArray>(instance->getResource()));
        }
    );
}