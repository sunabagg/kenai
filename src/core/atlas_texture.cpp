#include "atlas_texture.h"

void kenai::core::bindAtlasTexture(sol::state &lua) {
    lua.new_usertype<kenai::core::AtlasTexture>("AtlasTexture",
        "new", sol::factories(
            []() { return new kenai::core::AtlasTexture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::Texture2D>(),
        "atlas", sol::property(
            &kenai::core::AtlasTexture::getAtlas, 
            &kenai::core::AtlasTexture::setAtlas
        ),
        "filterClip", sol::property(
            &kenai::core::AtlasTexture::getFilterClip, 
            &kenai::core::AtlasTexture::setFilterClip
        ),
        "margin", sol::property(
            &kenai::core::AtlasTexture::getMargin, 
            &kenai::core::AtlasTexture::setMargin
        ),
        "region", sol::property(
            &kenai::core::AtlasTexture::getRegion, 
            &kenai::core::AtlasTexture::setRegion
        ),
        "cast", [](Resource* instance) {
            return new AtlasTexture(godot::Object::cast_to<GodotAtlasTexture>(instance->getResource()));
        }
    );
}