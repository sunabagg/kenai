#include "placeholder_texture_layered.h"

void lucidware::core::bindPlaceholderTextureLayered(sol::state &lua) {
    lua.new_usertype<lucidware::core::PlaceholderTextureLayered>("PlaceholderTextureLayered",
        "new", sol::factories(
            []() { return new lucidware::core::PlaceholderTextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered>(),
        "layers", sol::property(
            &lucidware::core::PlaceholderTextureLayered::getLayers,
            &lucidware::core::PlaceholderTextureLayered::setLayers
        ),
        "size", sol::property(
            &lucidware::core::PlaceholderTextureLayered::getSize,
            &lucidware::core::PlaceholderTextureLayered::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTextureLayered(godot::Object::cast_to<GodotPlaceholderTextureLayered>(instance->getResource()));
        }
    );
}