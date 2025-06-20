#include "texture2d.h"

void sunaba::core::bindTexture2D(sol::state &lua) {
    lua.new_usertype<sunaba::core::Texture2D>("Texture2D",
        "new", sol::factories(
            []() { return new sunaba::core::Texture2D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture>(),
        "createPlaceholder", &sunaba::core::Texture2D::createPlaceholder,
        "getHeight", &sunaba::core::Texture2D::getHeight,
        "getImage", &sunaba::core::Texture2D::getImage,
        "getSize", &sunaba::core::Texture2D::getSize,
        "getWidth", &sunaba::core::Texture2D::getWidth,
        "hasAlpha", &sunaba::core::Texture2D::hasAlpha,
        "cast", [](Resource* instance) {
            return new Texture2D(godot::Object::cast_to<GodotTexture2D>(instance->getResource()));
        }
    );
}