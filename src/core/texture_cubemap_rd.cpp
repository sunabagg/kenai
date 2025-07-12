#include "texture_cubemap_rd.h"

void kenai::core::bindTextureCubemapRD(sol::state &lua) {
    lua.new_usertype<kenai::core::TextureCubemapRD>("TextureCubemapRD",
        "new", sol::factories(
            []() { return new kenai::core::TextureCubemapRD(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered, kenai::core::TextureLayeredRD>(),
        "cast", [](kenai::core::Resource* instance) {
            return new TextureCubemapRD(godot::Object::cast_to<GodotTextureCubemapRD>(instance->getResource()));
        }
    );
}