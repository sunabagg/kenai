#include "image_texture.h"

void lucidfx::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<lucidfx::core::ImageTexture>("ImageTexture",
        "new", sol::factories(
            []() { return new lucidfx::core::ImageTexture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::Texture2D>(),
        "image", sol::property(
            &lucidfx::core::ImageTexture::getImage, 
            &lucidfx::core::ImageTexture::setImage
        ),
        "createFromImage", &lucidfx::core::ImageTexture::createFromImage,
        "getFormat", &lucidfx::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(godot::Object::cast_to<GodotImageTexture>(instance->getResource()));
        }
    );
}