#include "image_texture.h"

void sunaba::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::ImageTexture>("ImageTexture",
        "new", sol::factories(
            []() { return new sunaba::core::ImageTexture(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::Texture2D>(),
        "image", sol::property(
            &sunaba::core::ImageTexture::getImage, 
            &sunaba::core::ImageTexture::setImage
        ),
        "createFromImage", &sunaba::core::ImageTexture::createFromImage,
        "getFormat", &sunaba::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(godot::Object::cast_to<GodotImageTexture>(instance->getResource()));
        }
    );
}