#include "atlas_texture.h"

void sunaba::core::bindAtlasTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::AtlasTexture>("AtlasTexture",
        "new", sol::factories(
            []() { return new sunaba::core::AtlasTexture(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::Texture2D>(),
        "atlas", sol::property(
            &sunaba::core::AtlasTexture::getAtlas, 
            &sunaba::core::AtlasTexture::setAtlas
        ),
        "filterClip", sol::property(
            &sunaba::core::AtlasTexture::getFilterClip, 
            &sunaba::core::AtlasTexture::setFilterClip
        ),
        "margin", sol::property(
            &sunaba::core::AtlasTexture::getMargin, 
            &sunaba::core::AtlasTexture::setMargin
        ),
        "region", sol::property(
            &sunaba::core::AtlasTexture::getRegion, 
            &sunaba::core::AtlasTexture::setRegion
        ),
        "cast", [](Resource* instance) {
            return new AtlasTexture(godot::Object::cast_to<GodotAtlasTexture>(instance->getResource()));
        }
    );
}