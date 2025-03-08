#include "placeholder_texture2d_array.h"

void sunaba::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<sunaba::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        sol::constructors<sunaba::core::PlaceholderTexture2DArray()>(),
        sol::base_classes, sol::bases<sunaba::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(dynamic_cast<GodotPlaceholderTexture2DArray*>(instance->getResource()));
        }
    );
}