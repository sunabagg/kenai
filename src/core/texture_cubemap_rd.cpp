#include "texture_cubemap_rd.h"

void lucidfx::core::bindTextureCubemapRD(sol::state &lua) {
    lua.new_usertype<lucidfx::core::TextureCubemapRD>("TextureCubemapRD",
        "new", sol::factories(
            []() { return new lucidfx::core::TextureCubemapRD(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered, lucidfx::core::TextureLayeredRD>(),
        "cast", [](lucidfx::core::Resource* instance) {
            return new TextureCubemapRD(godot::Object::cast_to<GodotTextureCubemapRD>(instance->getResource()));
        }
    );
}