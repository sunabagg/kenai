#include "font.h"

void lucidfx::core::bindFont(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Font>("Font",
        "new", sol::factories(
            []() { return new lucidfx::core::Font(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "fallbacks", sol::property(
            &lucidfx::core::Font::getFallbacks, 
            &lucidfx::core::Font::setFallbacks
        ),
        "getAscent", &lucidfx::core::Font::getAscent,
        "getCharSize", &lucidfx::core::Font::getCharSize,
        "getDescent", &lucidfx::core::Font::getDescent,
        "getFaceCount", &lucidfx::core::Font::getFaceCount,
        "getFontName", &lucidfx::core::Font::getFontName,
        "getFontStyle", &lucidfx::core::Font::getFontStyle,
        "getFontWeight", &lucidfx::core::Font::getFontWeight,
        "getHeight", &lucidfx::core::Font::getHeight,
        "getMultilineStringSize", &lucidfx::core::Font::getMultilineStringSize,
        "getOpentypeFeatures", &lucidfx::core::Font::getOpentypeFeatures,
        "getOtNameStrings", &lucidfx::core::Font::getOtNameStrings,
        "getSpacing", &lucidfx::core::Font::getSpacing,
        "getStringSize", &lucidfx::core::Font::getStringSize,
        "getSupportedChars", &lucidfx::core::Font::getSupportedChars,
        "getSupportedFeatureList", &lucidfx::core::Font::getSupportedFeatureList,
        "getSupportedVariationList", &lucidfx::core::Font::getSupportedVariationList,
        "getUnderlinePosition", &lucidfx::core::Font::getUnderlinePosition,
        "getUnderlineThickness", &lucidfx::core::Font::getUnderlineThickness,
        "hasChar", &lucidfx::core::Font::hasChar,
        "isLanguageSupported", &lucidfx::core::Font::isLanguageSupported,
        "isScriptSupported", &lucidfx::core::Font::isScriptSupported,
        "setCacheCapacity", &lucidfx::core::Font::setCacheCapacity,
        "cast", [](Resource* instance) {
            return new Font(godot::Object::cast_to<GodotFont>(instance->getResource()));
        }
    );
}