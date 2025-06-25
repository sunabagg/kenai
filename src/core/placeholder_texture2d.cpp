#include "placeholder_texture2d.h"

void lucidfx::core::bindPlaceholderTexture2D(sol::state &lua) {
    lua.new_usertype<lucidfx::core::PlaceholderTexture2D>("PlaceholderTexture2D",
        "new", sol::factories(
            []() { return new lucidfx::core::PlaceholderTexture2D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::Texture2D>(),
        "size", sol::property(
            &lucidfx::core::PlaceholderTexture2D::getSize, 
            &lucidfx::core::PlaceholderTexture2D::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2D(godot::Object::cast_to<GodotPlaceholderTexture2D>(instance->getResource()));
        }
    );
}