#include "cubemap_array.h"

void lucidware::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::CubemapArray>("CubemapArray",
        "new", sol::factories(
            []() { return new lucidware::spatial::CubemapArray(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered, lucidware::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder,
        "cast", [](lucidware::core::Resource* instance) {
            return new CubemapArray(godot::Object::cast_to<GodotCubemapArray>(instance->getResource()));
        }
    );
}