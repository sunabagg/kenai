#include "texture2d.h"

void lucidware::core::bindTexture2D(sol::state &lua) {
    lua.new_usertype<lucidware::core::Texture2D>("Texture2D",
        "new", sol::factories(
            []() { return new lucidware::core::Texture2D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture>(),
        "createPlaceholder", &lucidware::core::Texture2D::createPlaceholder,
        "getHeight", &lucidware::core::Texture2D::getHeight,
        "getImage", &lucidware::core::Texture2D::getImage,
        "getSize", &lucidware::core::Texture2D::getSize,
        "getWidth", &lucidware::core::Texture2D::getWidth,
        "hasAlpha", &lucidware::core::Texture2D::hasAlpha,
        "cast", [](Resource* instance) {
            return new Texture2D(godot::Object::cast_to<GodotTexture2D>(instance->getResource()));
        }
    );
}