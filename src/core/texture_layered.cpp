#include "texture_layered.h"

void lucidware::core::bindTextureLayered(sol::state &lua) {
    lua.new_usertype<lucidware::core::TextureLayered>("TextureLayered",
        "new", sol::factories(
            []() { return new lucidware::core::TextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture>(),
        "getFormat", &lucidware::core::TextureLayered::getFormat,
        "getHeight", &lucidware::core::TextureLayered::getHeight,
        "getLayerData", &lucidware::core::TextureLayered::getLayerData,
        "getLayeredType", &lucidware::core::TextureLayered::getLayeredType,
        "getLayers", &lucidware::core::TextureLayered::getLayers,
        "getWidth", &lucidware::core::TextureLayered::getWidth,
        "cast", [](Resource* instance) {
            return new TextureLayered(godot::Object::cast_to<GodotTextureLayered>(instance->getResource()));
        }
    );
}