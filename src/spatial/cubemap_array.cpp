#include "cubemap_array.h"

void kenai::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::CubemapArray>("CubemapArray",
        "new", sol::factories(
            []() { return new kenai::spatial::CubemapArray(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered, kenai::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder,
        "cast", [](kenai::core::Resource* instance) {
            return new CubemapArray(godot::Object::cast_to<GodotCubemapArray>(instance->getResource()));
        }
    );
}