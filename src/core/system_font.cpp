#include "system_font.h"

void lucidware::core::bindSystemFont(sol::state_view& lua) {
    lua.new_usertype<SystemFont>("SystemFont",
        "new", sol::factories(
            []() { return new SystemFont(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Font>(),
        "allowSystemFallback", sol::property(&SystemFont::getAllowSystemFallback, &SystemFont::setAllowSystemFallback),
        "antialiasing", sol::property(&SystemFont::getAntialiasing, &SystemFont::setAntialiasing),
        "disableEmbeddedBitmaps", sol::property(&SystemFont::getDisableEmbeddedBitmaps, &SystemFont::setDisableEmbeddedBitmaps),
        "fontItalic", sol::property(&SystemFont::GetFontItalic, &SystemFont::SetFontItalic),
        "fontNames", sol::property(&SystemFont::getFontNames, &SystemFont::setFontNames),
        "fontStretch", sol::property(&SystemFont::getFontStretch, &SystemFont::setFontStretch),
        "fontWeight", sol::property(&SystemFont::getFontWeight, &SystemFont::setFontWeight),
        "forceAutohinter", sol::property(&SystemFont::getForceAutohinter, &SystemFont::setForceAutohinter),
        "generateMipmaps", sol::property(&SystemFont::getGenerateMipmaps, &SystemFont::setGenerateMipmaps),
        "hinting", sol::property(&SystemFont::getHinting, &SystemFont::setHinting),
        "keepRoundingRemainders", sol::property(&SystemFont::getKeepRoundingRemainders),
        "msdfPixelRange", sol::property(&SystemFont::getMsdfPixelRange, &SystemFont::setMsdfPixelRange),
        "msdfSize", sol::property(&SystemFont::getMsdfSize),
        "multichannelSignedDistanceField", sol::property(&SystemFont::getMultichannelSignedDistanceField, &SystemFont::setMultichannelSignedDistanceField),
        "oversampling", sol::property(&SystemFont::getOversampling, &SystemFont::setOversampling),
        "subpixelPositioning", sol::property(&SystemFont::getSubpixelPositioning, &SystemFont::setSubpixelPositioning),
        "cast", [](Resource* instance) {
            return new SystemFont(godot::Object::cast_to<GodotSystemFont>(instance->getResource()));
        });
}