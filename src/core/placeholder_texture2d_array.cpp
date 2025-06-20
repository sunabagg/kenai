#include "placeholder_texture2d_array.h"

void sunaba::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<sunaba::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        "new", sol::factories(
            []() { return new sunaba::core::PlaceholderTexture2DArray(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(godot::Object::cast_to<GodotPlaceholderTexture2DArray>(instance->getResource()));
        }
    );
}