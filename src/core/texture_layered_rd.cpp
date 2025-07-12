#include "texture_layered_rd.h"

void kenai::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<kenai::core::TextureLayeredRD>("TextureLayeredRD",
        "new", sol::factories(
            []() { return new kenai::core::TextureLayeredRD(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(godot::Object::cast_to<GodotTextureLayeredRD>(instance->getResource()));
        }
    );
}