#include "texture_cubemap_rd.h"

void lucidware::core::bindTextureCubemapRD(sol::state &lua) {
    lua.new_usertype<lucidware::core::TextureCubemapRD>("TextureCubemapRD",
        "new", sol::factories(
            []() { return new lucidware::core::TextureCubemapRD(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered, lucidware::core::TextureLayeredRD>(),
        "cast", [](lucidware::core::Resource* instance) {
            return new TextureCubemapRD(godot::Object::cast_to<GodotTextureCubemapRD>(instance->getResource()));
        }
    );
}