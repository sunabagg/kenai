#include "texture_layered.h"

void kenai::core::bindTextureLayered(sol::state &lua) {
    lua.new_usertype<kenai::core::TextureLayered>("TextureLayered",
        "new", sol::factories(
            []() { return new kenai::core::TextureLayered(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture>(),
        "getFormat", &kenai::core::TextureLayered::getFormat,
        "getHeight", &kenai::core::TextureLayered::getHeight,
        "getLayerData", &kenai::core::TextureLayered::getLayerData,
        "getLayeredType", &kenai::core::TextureLayered::getLayeredType,
        "getLayers", &kenai::core::TextureLayered::getLayers,
        "getWidth", &kenai::core::TextureLayered::getWidth,
        "cast", [](Resource* instance) {
            return new TextureLayered(godot::Object::cast_to<GodotTextureLayered>(instance->getResource()));
        }
    );
}