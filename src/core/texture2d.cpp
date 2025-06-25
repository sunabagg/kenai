#include "texture2d.h"

void lucidfx::core::bindTexture2D(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Texture2D>("Texture2D",
        "new", sol::factories(
            []() { return new lucidfx::core::Texture2D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture>(),
        "createPlaceholder", &lucidfx::core::Texture2D::createPlaceholder,
        "getHeight", &lucidfx::core::Texture2D::getHeight,
        "getImage", &lucidfx::core::Texture2D::getImage,
        "getSize", &lucidfx::core::Texture2D::getSize,
        "getWidth", &lucidfx::core::Texture2D::getWidth,
        "hasAlpha", &lucidfx::core::Texture2D::hasAlpha,
        "cast", [](Resource* instance) {
            return new Texture2D(godot::Object::cast_to<GodotTexture2D>(instance->getResource()));
        }
    );
}