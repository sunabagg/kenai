#include "atlas_texture.h"

void lucidware::core::bindAtlasTexture(sol::state &lua) {
    lua.new_usertype<lucidware::core::AtlasTexture>("AtlasTexture",
        "new", sol::factories(
            []() { return new lucidware::core::AtlasTexture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::Texture2D>(),
        "atlas", sol::property(
            &lucidware::core::AtlasTexture::getAtlas, 
            &lucidware::core::AtlasTexture::setAtlas
        ),
        "filterClip", sol::property(
            &lucidware::core::AtlasTexture::getFilterClip, 
            &lucidware::core::AtlasTexture::setFilterClip
        ),
        "margin", sol::property(
            &lucidware::core::AtlasTexture::getMargin, 
            &lucidware::core::AtlasTexture::setMargin
        ),
        "region", sol::property(
            &lucidware::core::AtlasTexture::getRegion, 
            &lucidware::core::AtlasTexture::setRegion
        ),
        "cast", [](Resource* instance) {
            return new AtlasTexture(godot::Object::cast_to<GodotAtlasTexture>(instance->getResource()));
        }
    );
}