#include "texture_layered.h"

void sunaba::core::bindTextureLayered(sol::state &lua) {
    lua.new_usertype<sunaba::core::TextureLayered>("TextureLayered",
        "new", sol::factories(
            []() { return new sunaba::core::TextureLayered(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture>(),
        "getFormat", &sunaba::core::TextureLayered::getFormat,
        "getHeight", &sunaba::core::TextureLayered::getHeight,
        "getLayerData", &sunaba::core::TextureLayered::getLayerData,
        "getLayeredType", &sunaba::core::TextureLayered::getLayeredType,
        "getLayers", &sunaba::core::TextureLayered::getLayers,
        "getWidth", &sunaba::core::TextureLayered::getWidth,
        "cast", [](Resource* instance) {
            return new TextureLayered(godot::Object::cast_to<GodotTextureLayered>(instance->getResource()));
        }
    );
}