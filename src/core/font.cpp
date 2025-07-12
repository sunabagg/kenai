#include "font.h"

void kenai::core::bindFont(sol::state &lua) {
    lua.new_usertype<kenai::core::Font>("Font",
        "new", sol::factories(
            []() { return new kenai::core::Font(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "fallbacks", sol::property(
            &kenai::core::Font::getFallbacks, 
            &kenai::core::Font::setFallbacks
        ),
        "getAscent", &kenai::core::Font::getAscent,
        "getCharSize", &kenai::core::Font::getCharSize,
        "getDescent", &kenai::core::Font::getDescent,
        "getFaceCount", &kenai::core::Font::getFaceCount,
        "getFontName", &kenai::core::Font::getFontName,
        "getFontStyle", &kenai::core::Font::getFontStyle,
        "getFontWeight", &kenai::core::Font::getFontWeight,
        "getHeight", &kenai::core::Font::getHeight,
        "getMultilineStringSize", &kenai::core::Font::getMultilineStringSize,
        "getOpentypeFeatures", &kenai::core::Font::getOpentypeFeatures,
        "getOtNameStrings", &kenai::core::Font::getOtNameStrings,
        "getSpacing", &kenai::core::Font::getSpacing,
        "getStringSize", &kenai::core::Font::getStringSize,
        "getSupportedChars", &kenai::core::Font::getSupportedChars,
        "getSupportedFeatureList", &kenai::core::Font::getSupportedFeatureList,
        "getSupportedVariationList", &kenai::core::Font::getSupportedVariationList,
        "getUnderlinePosition", &kenai::core::Font::getUnderlinePosition,
        "getUnderlineThickness", &kenai::core::Font::getUnderlineThickness,
        "hasChar", &kenai::core::Font::hasChar,
        "isLanguageSupported", &kenai::core::Font::isLanguageSupported,
        "isScriptSupported", &kenai::core::Font::isScriptSupported,
        "setCacheCapacity", &kenai::core::Font::setCacheCapacity,
        "cast", [](Resource* instance) {
            return new Font(godot::Object::cast_to<GodotFont>(instance->getResource()));
        }
    );
}