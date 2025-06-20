#include "image_texture_layered.h"

void sunaba::core::bindImageTextureLayered(sol::state_view& lua) {
    lua.new_usertype<sunaba::core::ImageTextureLayered>("ImageTextureLayered",
        "new", sol::factories(
            []() { return new sunaba::core::ImageTextureLayered(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered>(),
        "createFromImages", &ImageTextureLayered::createFromImages,
        "updateLayer", &ImageTextureLayered::updateLayer,
        "cast", [](sunaba::core::Resource* instance) {
            return new ImageTextureLayered(godot::Object::cast_to<GodotImageTextureLayered>(instance->getResource()));
        }
    );
}