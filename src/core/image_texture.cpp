#include "image_texture.h"

void kenai::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<kenai::core::ImageTexture>("ImageTexture",
        "new", sol::factories(
            []() { return new kenai::core::ImageTexture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::Texture2D>(),
        "image", sol::property(
            &kenai::core::ImageTexture::getImage, 
            &kenai::core::ImageTexture::setImage
        ),
        "createFromImage", &kenai::core::ImageTexture::createFromImage,
        "getFormat", &kenai::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(godot::Object::cast_to<GodotImageTexture>(instance->getResource()));
        }
    );
}