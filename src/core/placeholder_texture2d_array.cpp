#include "placeholder_texture2d_array.h"

void lucidfx::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<lucidfx::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        "new", sol::factories(
            []() { return new lucidfx::core::PlaceholderTexture2DArray(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered, lucidfx::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(godot::Object::cast_to<GodotPlaceholderTexture2DArray>(instance->getResource()));
        }
    );
}