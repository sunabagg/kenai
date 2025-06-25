#include "image_texture_layered.h"

void lucidware::core::bindImageTextureLayered(sol::state_view& lua) {
    lua.new_usertype<lucidware::core::ImageTextureLayered>("ImageTextureLayered",
        "new", sol::factories(
            []() { return new lucidware::core::ImageTextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered>(),
        "createFromImages", &ImageTextureLayered::createFromImages,
        "updateLayer", &ImageTextureLayered::updateLayer,
        "cast", [](lucidware::core::Resource* instance) {
            return new ImageTextureLayered(godot::Object::cast_to<GodotImageTextureLayered>(instance->getResource()));
        }
    );
}