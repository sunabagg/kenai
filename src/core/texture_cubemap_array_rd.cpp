#include "texture_cubemap_array_rd.h"

void kenai::core::bindTextureCubemapArrayRD(sol::state &lua) {
    lua.new_usertype<kenai::core::TextureCubemapArrayRD>("TextureCubemapArrayRD",
        "new", sol::factories(
            []() { return new kenai::core::TextureCubemapArrayRD(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered, kenai::core::TextureLayeredRD>(),
        "cast", [](kenai::core::Resource* instance) {
            return new TextureCubemapArrayRD(godot::Object::cast_to<GodotTextureCubemapArrayRD>(instance->getResource()));
        }
    );
}