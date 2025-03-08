#include "placeholder_texture2d.h"

void sunaba::core::bindPlaceholderTexture2D(sol::state &lua) {
    lua.new_usertype<sunaba::core::PlaceholderTexture2D>("PlaceholderTexture2D",
        sol::constructors<sunaba::core::PlaceholderTexture2D()>(),
        sol::base_classes, sol::bases<sunaba::core::Texture2D>(),
        "size", sol::property(
            &sunaba::core::PlaceholderTexture2D::getSize, 
            &sunaba::core::PlaceholderTexture2D::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2D(dynamic_cast<GodotPlaceholderTexture2D*>(instance->getResource()));
        }
    );
}