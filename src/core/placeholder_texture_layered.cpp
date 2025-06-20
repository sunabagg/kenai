#include "placeholder_texture_layered.h"

void sunaba::core::bindPlaceholderTextureLayered(sol::state &lua) {
    lua.new_usertype<sunaba::core::PlaceholderTextureLayered>("PlaceholderTextureLayered",
        "new", sol::factories(
            []() { return new sunaba::core::PlaceholderTextureLayered(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered>(),
        "layers", sol::property(
            &sunaba::core::PlaceholderTextureLayered::getLayers,
            &sunaba::core::PlaceholderTextureLayered::setLayers
        ),
        "size", sol::property(
            &sunaba::core::PlaceholderTextureLayered::getSize,
            &sunaba::core::PlaceholderTextureLayered::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTextureLayered(godot::Object::cast_to<GodotPlaceholderTextureLayered>(instance->getResource()));
        }
    );
}