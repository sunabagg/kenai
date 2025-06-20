#include "texture.h"

void sunaba::core::bindTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::Texture>("Texture",
        "new", sol::factories(
            []() { return new sunaba::core::Texture(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "cast", [](Resource* instance) {
            return new Texture(godot::Object::cast_to<GodotTexture>(instance->getResource()));
        }
    );
}