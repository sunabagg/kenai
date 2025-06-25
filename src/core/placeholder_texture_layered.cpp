#include "placeholder_texture_layered.h"

void lucidfx::core::bindPlaceholderTextureLayered(sol::state &lua) {
    lua.new_usertype<lucidfx::core::PlaceholderTextureLayered>("PlaceholderTextureLayered",
        "new", sol::factories(
            []() { return new lucidfx::core::PlaceholderTextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered>(),
        "layers", sol::property(
            &lucidfx::core::PlaceholderTextureLayered::getLayers,
            &lucidfx::core::PlaceholderTextureLayered::setLayers
        ),
        "size", sol::property(
            &lucidfx::core::PlaceholderTextureLayered::getSize,
            &lucidfx::core::PlaceholderTextureLayered::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTextureLayered(godot::Object::cast_to<GodotPlaceholderTextureLayered>(instance->getResource()));
        }
    );
}