#include "image_texture_layered.h"

void kenai::core::bindImageTextureLayered(sol::state_view& lua) {
    lua.new_usertype<kenai::core::ImageTextureLayered>("ImageTextureLayered",
        "new", sol::factories(
            []() { return new kenai::core::ImageTextureLayered(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered>(),
        "createFromImages", &ImageTextureLayered::createFromImages,
        "updateLayer", &ImageTextureLayered::updateLayer,
        "cast", [](kenai::core::Resource* instance) {
            return new ImageTextureLayered(godot::Object::cast_to<GodotImageTextureLayered>(instance->getResource()));
        }
    );
}