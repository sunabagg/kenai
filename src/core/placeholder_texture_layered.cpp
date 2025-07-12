#include "placeholder_texture_layered.h"

void kenai::core::bindPlaceholderTextureLayered(sol::state &lua) {
    lua.new_usertype<kenai::core::PlaceholderTextureLayered>("PlaceholderTextureLayered",
        "new", sol::factories(
            []() { return new kenai::core::PlaceholderTextureLayered(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered>(),
        "layers", sol::property(
            &kenai::core::PlaceholderTextureLayered::getLayers,
            &kenai::core::PlaceholderTextureLayered::setLayers
        ),
        "size", sol::property(
            &kenai::core::PlaceholderTextureLayered::getSize,
            &kenai::core::PlaceholderTextureLayered::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTextureLayered(godot::Object::cast_to<GodotPlaceholderTextureLayered>(instance->getResource()));
        }
    );
}