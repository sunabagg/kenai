#include "image_texture.h"

void sunaba::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::ImageTexture>("ImageTexture",
        sol::constructors<sunaba::core::ImageTexture()>(),
        sol::base_classes, sol::bases<sunaba::core::Texture2D>(),
        "image", sol::property(
            &sunaba::core::ImageTexture::getImage, 
            &sunaba::core::ImageTexture::setImage
        ),
        "createFromImage", &sunaba::core::ImageTexture::createFromImage,
        "getFormat", &sunaba::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(static_cast<GodotImageTexture*>(instance->getResource()));
        }
    );
}