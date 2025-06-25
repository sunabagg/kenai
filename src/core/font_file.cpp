#include "font_file.h"

void lucidfx::core::bindFontFile(sol::state &lua) {
    lua.new_usertype<lucidfx::core::FontFile>("FontFile",
        "new", sol::factories(
            []() { return new lucidfx::core::FontFile(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Font>(),

        "allowSystemFallback", sol::property(
            &lucidfx::core::FontFile::getAllowSystemFallback,
            &lucidfx::core::FontFile::setAllowSystemFallback
        ),
        "antialiasing", sol::property(
            &lucidfx::core::FontFile::getAntialiasing,
            &lucidfx::core::FontFile::setAntialiasing
        ),
        "data", sol::property(
            &lucidfx::core::FontFile::getData,
            &lucidfx::core::FontFile::setData
        ),
        "disableEmbeddedBitmaps", sol::property(
            &lucidfx::core::FontFile::getDisableEmbeddedBitmaps,
            &lucidfx::core::FontFile::setDisableEmbeddedBitmaps
        ),
        "fixedSize", sol::property(
            &lucidfx::core::FontFile::getFixedSize,
            &lucidfx::core::FontFile::setFixedSize
        ),
        "fixedSizeScaleMode", sol::property(
            &lucidfx::core::FontFile::getFixedSizeScaleMode,
            &lucidfx::core::FontFile::setFixedSizeScaleMode
        ),
        "fontName", sol::property(
            &lucidfx::core::FontFile::getFontName,
            &lucidfx::core::FontFile::setFontName
        ),
        "fontStretch", sol::property(
            &lucidfx::core::FontFile::getFontStretch,
            &lucidfx::core::FontFile::setFontStretch
        ),
        "fontStyle", sol::property(
            &lucidfx::core::FontFile::getFontStyle,
            &lucidfx::core::FontFile::setFontStyle
        ),
        "fontWeight", sol::property(
            &lucidfx::core::FontFile::getFontWeight,
            &lucidfx::core::FontFile::setFontWeight
        ),
        "forceAutohinter", sol::property(
            &lucidfx::core::FontFile::getForceAutohinter,
            &lucidfx::core::FontFile::setForceAutohinter
        ),
        "generateMipmaps", sol::property(
            &lucidfx::core::FontFile::getGenerateMipmaps,
            &lucidfx::core::FontFile::setGenerateMipmaps
        ),
        "hinting", sol::property(
            &lucidfx::core::FontFile::getHinting,
            &lucidfx::core::FontFile::setHinting
        ),
        "msdfPixelRange", sol::property(
            &lucidfx::core::FontFile::getMsdfPixelRange,
            &lucidfx::core::FontFile::setMsdfPixelRange
        ),
        "msdfSize", sol::property(
            &lucidfx::core::FontFile::getMsdfSize,
            &lucidfx::core::FontFile::setMsdfSize
        ),
        "multichannelSignedDistanceField", sol::property(
            &lucidfx::core::FontFile::getMultichannelSignedDistanceField,
            &lucidfx::core::FontFile::setMultichannelSignedDistanceField
        ),
        "opentypeFeatureOverrides", sol::property(
            &lucidfx::core::FontFile::getOpentypeFeatureOverrides,
            &lucidfx::core::FontFile::setOpentypeFeatureOverrides
        ),
        "oversampling", sol::property(
            &lucidfx::core::FontFile::getOversampling,
            &lucidfx::core::FontFile::setOversampling
        ),
        "styleName", sol::property(
            &lucidfx::core::FontFile::getStyleName,
            &lucidfx::core::FontFile::setStyleName
        ),
        "subpixelPositioning", sol::property(
            &lucidfx::core::FontFile::getSubpixelPositioning,
            &lucidfx::core::FontFile::setSubpixelPositioning
        ),
        "clearCache", &lucidfx::core::FontFile::clearCache,
        "clearGlyphs", &lucidfx::core::FontFile::clearGlyphs,
        "clearKerningMap", &lucidfx::core::FontFile::clearKerningMap,
        "getFallbacks", &lucidfx::core::FontFile::getFallbacks,
        "getFaceIndex", &lucidfx::core::FontFile::getFaceIndex,
        "getFontName", &lucidfx::core::FontFile::getFontName,
        "getGlyphAdvance", &lucidfx::core::FontFile::getGlyphAdvance,
        "getGlyphIndex", &lucidfx::core::FontFile::getGlyphIndex,
        "getGlyphList", &lucidfx::core::FontFile::getGlyphList,
        "getGlyphOffset", &lucidfx::core::FontFile::getGlyphOffset,
        "getGlyphSize", &lucidfx::core::FontFile::getGlyphSize,
        "getKerning", &lucidfx::core::FontFile::getKerning,
        "getKerningList", &lucidfx::core::FontFile::getKerningList,
        "getLanguageSupportOverride", &lucidfx::core::FontFile::getLanguageSupportOverride,
        "getScriptSupportOverride", &lucidfx::core::FontFile::getScriptSupportOverride,
        "getMsdfPixelRange", &lucidfx::core::FontFile::getMsdfPixelRange,
        "getMsdfSize", &lucidfx::core::FontFile::getMsdfSize,
        "getOversampling", &lucidfx::core::FontFile::getOversampling,
        "getSizeCacheList", &lucidfx::core::FontFile::getSizeCacheList,
        "getTextureCount", &lucidfx::core::FontFile::getTextureCount,
        "getTextureImage", &lucidfx::core::FontFile::getTextureImage,
        "getTextureOffsets", &lucidfx::core::FontFile::getTextureOffsets,
        "getTransform", &lucidfx::core::FontFile::getTransform,
        "getVariationCoordinates", &lucidfx::core::FontFile::getVariationCoordinates,
        "isLanguageSupported", &lucidfx::core::FontFile::isLanguageSupported,
        "isScriptSupported", &lucidfx::core::FontFile::isScriptSupported,
        "loadBitmapFont", &lucidfx::core::FontFile::loadBitmapFont,
        "loadDynamicFont", &lucidfx::core::FontFile::loadDynamicFont,
        "setCacheCapacity", &lucidfx::core::FontFile::setCacheCapacity,
        "setFallbacks", &lucidfx::core::FontFile::setFallbacks,
        "setFontName", &lucidfx::core::FontFile::setFontName,
        "setFontStyle", &lucidfx::core::FontFile::setFontStyle,
        "setFontWeight", &lucidfx::core::FontFile::setFontWeight,
        "setGlyphAdvance", &lucidfx::core::FontFile::setGlyphAdvance,
        "setGlyphOffset", &lucidfx::core::FontFile::setGlyphOffset,
        "setGlyphSize", &lucidfx::core::FontFile::setGlyphSize,
        "setGlyphTextureIndex", &lucidfx::core::FontFile::setGlyphTextureIndex,
        "setGlyphUvRect", &lucidfx::core::FontFile::setGlyphUvRect,
        "setKerning", &lucidfx::core::FontFile::setKerning,
        "setLanguageSupportOverride", &lucidfx::core::FontFile::setLanguageSupportOverride,
        "setScriptSupportOverride", &lucidfx::core::FontFile::setScriptSupportOverride,
        "setTextureImage", &lucidfx::core::FontFile::setTextureImage,
        "setTextureOffsets", &lucidfx::core::FontFile::setTextureOffsets,
        "setTransform", &lucidfx::core::FontFile::setTransform,
        "setVariationCoordinates", &lucidfx::core::FontFile::setVariationCoordinates,
        "cast", [](Resource* instance) {
            return new FontFile(godot::Object::cast_to<GodotFontFile>(instance->getResource()));
        }
    );
}