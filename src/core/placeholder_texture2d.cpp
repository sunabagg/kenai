#include "placeholder_texture2d.h"

void kenai::core::bindPlaceholderTexture2D(sol::state &lua) {
    lua.new_usertype<kenai::core::PlaceholderTexture2D>("PlaceholderTexture2D",
        "new", sol::factories(
            []() { return new kenai::core::PlaceholderTexture2D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::Texture2D>(),
        "size", sol::property(
            &kenai::core::PlaceholderTexture2D::getSize, 
            &kenai::core::PlaceholderTexture2D::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2D(godot::Object::cast_to<GodotPlaceholderTexture2D>(instance->getResource()));
        }
    );
}