#include "placeholder_texture2d.h"

void lucidware::core::bindPlaceholderTexture2D(sol::state &lua) {
    lua.new_usertype<lucidware::core::PlaceholderTexture2D>("PlaceholderTexture2D",
        "new", sol::factories(
            []() { return new lucidware::core::PlaceholderTexture2D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::Texture2D>(),
        "size", sol::property(
            &lucidware::core::PlaceholderTexture2D::getSize, 
            &lucidware::core::PlaceholderTexture2D::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2D(godot::Object::cast_to<GodotPlaceholderTexture2D>(instance->getResource()));
        }
    );
}