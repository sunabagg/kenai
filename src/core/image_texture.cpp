#include "image_texture.h"

void lucidware::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<lucidware::core::ImageTexture>("ImageTexture",
        "new", sol::factories(
            []() { return new lucidware::core::ImageTexture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::Texture2D>(),
        "image", sol::property(
            &lucidware::core::ImageTexture::getImage, 
            &lucidware::core::ImageTexture::setImage
        ),
        "createFromImage", &lucidware::core::ImageTexture::createFromImage,
        "getFormat", &lucidware::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(godot::Object::cast_to<GodotImageTexture>(instance->getResource()));
        }
    );
}