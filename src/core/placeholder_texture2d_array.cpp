#include "placeholder_texture2d_array.h"

void lucidware::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<lucidware::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        "new", sol::factories(
            []() { return new lucidware::core::PlaceholderTexture2DArray(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered, lucidware::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(godot::Object::cast_to<GodotPlaceholderTexture2DArray>(instance->getResource()));
        }
    );
}