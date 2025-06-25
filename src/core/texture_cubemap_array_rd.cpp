#include "texture_cubemap_array_rd.h"

void lucidware::core::bindTextureCubemapArrayRD(sol::state &lua) {
    lua.new_usertype<lucidware::core::TextureCubemapArrayRD>("TextureCubemapArrayRD",
        "new", sol::factories(
            []() { return new lucidware::core::TextureCubemapArrayRD(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered, lucidware::core::TextureLayeredRD>(),
        "cast", [](lucidware::core::Resource* instance) {
            return new TextureCubemapArrayRD(godot::Object::cast_to<GodotTextureCubemapArrayRD>(instance->getResource()));
        }
    );
}