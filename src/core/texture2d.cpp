#include "texture2d.h"

void kenai::core::bindTexture2D(sol::state &lua) {
    lua.new_usertype<kenai::core::Texture2D>("Texture2D",
        "new", sol::factories(
            []() { return new kenai::core::Texture2D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture>(),
        "createPlaceholder", &kenai::core::Texture2D::createPlaceholder,
        "getHeight", &kenai::core::Texture2D::getHeight,
        "getImage", &kenai::core::Texture2D::getImage,
        "getSize", &kenai::core::Texture2D::getSize,
        "getWidth", &kenai::core::Texture2D::getWidth,
        "hasAlpha", &kenai::core::Texture2D::hasAlpha,
        "cast", [](Resource* instance) {
            return new Texture2D(godot::Object::cast_to<GodotTexture2D>(instance->getResource()));
        }
    );
}