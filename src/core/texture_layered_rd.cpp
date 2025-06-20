#include "texture_layered_rd.h"

void sunaba::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<sunaba::core::TextureLayeredRD>("TextureLayeredRD",
        "new", sol::factories(
            []() { return new sunaba::core::TextureLayeredRD(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(godot::Object::cast_to<GodotTextureLayeredRD>(instance->getResource()));
        }
    );
}