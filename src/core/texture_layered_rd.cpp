#include "texture_layered_rd.h"

void lucidfx::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<lucidfx::core::TextureLayeredRD>("TextureLayeredRD",
        "new", sol::factories(
            []() { return new lucidfx::core::TextureLayeredRD(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(godot::Object::cast_to<GodotTextureLayeredRD>(instance->getResource()));
        }
    );
}