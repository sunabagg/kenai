#include "image_texture_layered.h"

void lucidfx::core::bindImageTextureLayered(sol::state_view& lua) {
    lua.new_usertype<lucidfx::core::ImageTextureLayered>("ImageTextureLayered",
        "new", sol::factories(
            []() { return new lucidfx::core::ImageTextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered>(),
        "createFromImages", &ImageTextureLayered::createFromImages,
        "updateLayer", &ImageTextureLayered::updateLayer,
        "cast", [](lucidfx::core::Resource* instance) {
            return new ImageTextureLayered(godot::Object::cast_to<GodotImageTextureLayered>(instance->getResource()));
        }
    );
}