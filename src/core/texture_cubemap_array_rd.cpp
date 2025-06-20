#include "texture_cubemap_array_rd.h"

void sunaba::core::bindTextureCubemapArrayRD(sol::state &lua) {
    lua.new_usertype<sunaba::core::TextureCubemapArrayRD>("TextureCubemapArrayRD",
        "new", sol::factories(
            []() { return new sunaba::core::TextureCubemapArrayRD(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::TextureLayeredRD>(),
        "cast", [](sunaba::core::Resource* instance) {
            return new TextureCubemapArrayRD(godot::Object::cast_to<GodotTextureCubemapArrayRD>(instance->getResource()));
        }
    );
}