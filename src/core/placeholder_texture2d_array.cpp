#include "placeholder_texture2d_array.h"

void kenai::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<kenai::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        "new", sol::factories(
            []() { return new kenai::core::PlaceholderTexture2DArray(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered, kenai::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(godot::Object::cast_to<GodotPlaceholderTexture2DArray>(instance->getResource()));
        }
    );
}