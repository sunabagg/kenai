#include "texture_layered.h"

void lucidfx::core::bindTextureLayered(sol::state &lua) {
    lua.new_usertype<lucidfx::core::TextureLayered>("TextureLayered",
        "new", sol::factories(
            []() { return new lucidfx::core::TextureLayered(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture>(),
        "getFormat", &lucidfx::core::TextureLayered::getFormat,
        "getHeight", &lucidfx::core::TextureLayered::getHeight,
        "getLayerData", &lucidfx::core::TextureLayered::getLayerData,
        "getLayeredType", &lucidfx::core::TextureLayered::getLayeredType,
        "getLayers", &lucidfx::core::TextureLayered::getLayers,
        "getWidth", &lucidfx::core::TextureLayered::getWidth,
        "cast", [](Resource* instance) {
            return new TextureLayered(godot::Object::cast_to<GodotTextureLayered>(instance->getResource()));
        }
    );
}