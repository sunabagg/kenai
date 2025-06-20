#include "font.h"

void sunaba::core::bindFont(sol::state &lua) {
    lua.new_usertype<sunaba::core::Font>("Font",
        "new", sol::factories(
            []() { return new sunaba::core::Font(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "fallbacks", sol::property(
            &sunaba::core::Font::getFallbacks, 
            &sunaba::core::Font::setFallbacks
        ),
        "getAscent", &sunaba::core::Font::getAscent,
        "getCharSize", &sunaba::core::Font::getCharSize,
        "getDescent", &sunaba::core::Font::getDescent,
        "getFaceCount", &sunaba::core::Font::getFaceCount,
        "getFontName", &sunaba::core::Font::getFontName,
        "getFontStyle", &sunaba::core::Font::getFontStyle,
        "getFontWeight", &sunaba::core::Font::getFontWeight,
        "getHeight", &sunaba::core::Font::getHeight,
        "getMultilineStringSize", &sunaba::core::Font::getMultilineStringSize,
        "getOpentypeFeatures", &sunaba::core::Font::getOpentypeFeatures,
        "getOtNameStrings", &sunaba::core::Font::getOtNameStrings,
        "getSpacing", &sunaba::core::Font::getSpacing,
        "getStringSize", &sunaba::core::Font::getStringSize,
        "getSupportedChars", &sunaba::core::Font::getSupportedChars,
        "getSupportedFeatureList", &sunaba::core::Font::getSupportedFeatureList,
        "getSupportedVariationList", &sunaba::core::Font::getSupportedVariationList,
        "getUnderlinePosition", &sunaba::core::Font::getUnderlinePosition,
        "getUnderlineThickness", &sunaba::core::Font::getUnderlineThickness,
        "hasChar", &sunaba::core::Font::hasChar,
        "isLanguageSupported", &sunaba::core::Font::isLanguageSupported,
        "isScriptSupported", &sunaba::core::Font::isScriptSupported,
        "setCacheCapacity", &sunaba::core::Font::setCacheCapacity,
        "cast", [](Resource* instance) {
            return new Font(godot::Object::cast_to<GodotFont>(instance->getResource()));
        }
    );
}