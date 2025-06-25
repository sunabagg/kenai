#include "texture_cubemap_array_rd.h"

void lucidfx::core::bindTextureCubemapArrayRD(sol::state &lua) {
    lua.new_usertype<lucidfx::core::TextureCubemapArrayRD>("TextureCubemapArrayRD",
        "new", sol::factories(
            []() { return new lucidfx::core::TextureCubemapArrayRD(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered, lucidfx::core::TextureLayeredRD>(),
        "cast", [](lucidfx::core::Resource* instance) {
            return new TextureCubemapArrayRD(godot::Object::cast_to<GodotTextureCubemapArrayRD>(instance->getResource()));
        }
    );
}