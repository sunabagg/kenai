#include "font.h"

void lucidware::core::bindFont(sol::state &lua) {
    lua.new_usertype<lucidware::core::Font>("Font",
        "new", sol::factories(
            []() { return new lucidware::core::Font(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "fallbacks", sol::property(
            &lucidware::core::Font::getFallbacks, 
            &lucidware::core::Font::setFallbacks
        ),
        "getAscent", &lucidware::core::Font::getAscent,
        "getCharSize", &lucidware::core::Font::getCharSize,
        "getDescent", &lucidware::core::Font::getDescent,
        "getFaceCount", &lucidware::core::Font::getFaceCount,
        "getFontName", &lucidware::core::Font::getFontName,
        "getFontStyle", &lucidware::core::Font::getFontStyle,
        "getFontWeight", &lucidware::core::Font::getFontWeight,
        "getHeight", &lucidware::core::Font::getHeight,
        "getMultilineStringSize", &lucidware::core::Font::getMultilineStringSize,
        "getOpentypeFeatures", &lucidware::core::Font::getOpentypeFeatures,
        "getOtNameStrings", &lucidware::core::Font::getOtNameStrings,
        "getSpacing", &lucidware::core::Font::getSpacing,
        "getStringSize", &lucidware::core::Font::getStringSize,
        "getSupportedChars", &lucidware::core::Font::getSupportedChars,
        "getSupportedFeatureList", &lucidware::core::Font::getSupportedFeatureList,
        "getSupportedVariationList", &lucidware::core::Font::getSupportedVariationList,
        "getUnderlinePosition", &lucidware::core::Font::getUnderlinePosition,
        "getUnderlineThickness", &lucidware::core::Font::getUnderlineThickness,
        "hasChar", &lucidware::core::Font::hasChar,
        "isLanguageSupported", &lucidware::core::Font::isLanguageSupported,
        "isScriptSupported", &lucidware::core::Font::isScriptSupported,
        "setCacheCapacity", &lucidware::core::Font::setCacheCapacity,
        "cast", [](Resource* instance) {
            return new Font(godot::Object::cast_to<GodotFont>(instance->getResource()));
        }
    );
}