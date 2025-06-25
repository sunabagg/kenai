#include "texture_layered_rd.h"

void lucidware::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<lucidware::core::TextureLayeredRD>("TextureLayeredRD",
        "new", sol::factories(
            []() { return new lucidware::core::TextureLayeredRD(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(godot::Object::cast_to<GodotTextureLayeredRD>(instance->getResource()));
        }
    );
}