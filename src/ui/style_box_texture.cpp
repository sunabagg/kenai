#include "style_box_texture.h"

void lucidware::ui::bindStyleBoxTexture(sol::state_view& lua) {
    lua.new_usertype<StyleBoxTexture>("StyleBoxTexture",
        "new", sol::factories(
            []() { return new StyleBoxTexture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::ui::StyleBox>(),
        "axisStretchHorizontal", sol::property(&StyleBoxTexture::getAxisStretchHorizontal, &StyleBoxTexture::setAxisStretchHorizontal),
        "axisStretchVertical", sol::property(&StyleBoxTexture::getAxisStretchVertical, &StyleBoxTexture::setAxisStretchVertical),
        "drawCenter", sol::property(&StyleBoxTexture::isDrawCenter, &StyleBoxTexture::setDrawCenter),
        "expandMarginBottom", sol::property(&StyleBoxTexture::getExpandMarginBottom, &StyleBoxTexture::setExpandMarginBottom),
        "expandMarginLeft", sol::property(&StyleBoxTexture::getExpandMarginLeft, &StyleBoxTexture::setExpandMarginLeft),
        "expandMarginRight", sol::property(&StyleBoxTexture::getExpandMarginRight, &StyleBoxTexture::setExpandMarginRight),
        "expandMarginTop", sol::property(&StyleBoxTexture::getExpandMarginTop, &StyleBoxTexture::setExpandMarginTop),
        "getExpandMargin", &StyleBoxTexture::getExpandMargin,
        "setExpandMarginAll", &StyleBoxTexture::setExpandMarginAll,
        "modulateColor", sol::property(&StyleBoxTexture::getModulateColor, &StyleBoxTexture::setModulateColor),
        "regionRect", sol::property(&StyleBoxTexture::getRegionRect, &StyleBoxTexture::setRegionRect),
        "texture", sol::property(&StyleBoxTexture::getTexture, &StyleBoxTexture::setTexture),
        "textureMarginBottom", sol::property(&StyleBoxTexture::getTextureMarginBottom, &StyleBoxTexture::setTextureMarginBottom),
        "textureMarginLeft", sol::property(&StyleBoxTexture::getTextureMarginLeft, &StyleBoxTexture::setTextureMarginLeft),
        "textureMarginRight", sol::property(&StyleBoxTexture::getTextureMarginRight, &StyleBoxTexture::setTextureMarginRight),
        "textureMarginTop", sol::property(&StyleBoxTexture::getTextureMarginTop, &StyleBoxTexture::setTextureMarginTop),
        "getTextureMargin", &StyleBoxTexture::getTextureMargin,
        "setTextureMarginAll", &StyleBoxTexture::setTextureMarginAll,
        "setTextureMargin", &StyleBoxTexture::setTextureMargin,
        "cast", [](lucidware::core::Resource* p_resource) {
            return new StyleBoxTexture(godot::Object::cast_to<GodotStyleBoxTexture>(p_resource->getResource()));
        }
    );
}