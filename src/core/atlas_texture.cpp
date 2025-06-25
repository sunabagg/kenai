#include "atlas_texture.h"

void lucidfx::core::bindAtlasTexture(sol::state &lua) {
    lua.new_usertype<lucidfx::core::AtlasTexture>("AtlasTexture",
        "new", sol::factories(
            []() { return new lucidfx::core::AtlasTexture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::Texture2D>(),
        "atlas", sol::property(
            &lucidfx::core::AtlasTexture::getAtlas, 
            &lucidfx::core::AtlasTexture::setAtlas
        ),
        "filterClip", sol::property(
            &lucidfx::core::AtlasTexture::getFilterClip, 
            &lucidfx::core::AtlasTexture::setFilterClip
        ),
        "margin", sol::property(
            &lucidfx::core::AtlasTexture::getMargin, 
            &lucidfx::core::AtlasTexture::setMargin
        ),
        "region", sol::property(
            &lucidfx::core::AtlasTexture::getRegion, 
            &lucidfx::core::AtlasTexture::setRegion
        ),
        "cast", [](Resource* instance) {
            return new AtlasTexture(godot::Object::cast_to<GodotAtlasTexture>(instance->getResource()));
        }
    );
}