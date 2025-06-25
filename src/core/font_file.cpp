#include "font_file.h"

void lucidware::core::bindFontFile(sol::state &lua) {
    lua.new_usertype<lucidware::core::FontFile>("FontFile",
        "new", sol::factories(
            []() { return new lucidware::core::FontFile(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Font>(),

        "allowSystemFallback", sol::property(
            &lucidware::core::FontFile::getAllowSystemFallback,
            &lucidware::core::FontFile::setAllowSystemFallback
        ),
        "antialiasing", sol::property(
            &lucidware::core::FontFile::getAntialiasing,
            &lucidware::core::FontFile::setAntialiasing
        ),
        "data", sol::property(
            &lucidware::core::FontFile::getData,
            &lucidware::core::FontFile::setData
        ),
        "disableEmbeddedBitmaps", sol::property(
            &lucidware::core::FontFile::getDisableEmbeddedBitmaps,
            &lucidware::core::FontFile::setDisableEmbeddedBitmaps
        ),
        "fixedSize", sol::property(
            &lucidware::core::FontFile::getFixedSize,
            &lucidware::core::FontFile::setFixedSize
        ),
        "fixedSizeScaleMode", sol::property(
            &lucidware::core::FontFile::getFixedSizeScaleMode,
            &lucidware::core::FontFile::setFixedSizeScaleMode
        ),
        "fontName", sol::property(
            &lucidware::core::FontFile::getFontName,
            &lucidware::core::FontFile::setFontName
        ),
        "fontStretch", sol::property(
            &lucidware::core::FontFile::getFontStretch,
            &lucidware::core::FontFile::setFontStretch
        ),
        "fontStyle", sol::property(
            &lucidware::core::FontFile::getFontStyle,
            &lucidware::core::FontFile::setFontStyle
        ),
        "fontWeight", sol::property(
            &lucidware::core::FontFile::getFontWeight,
            &lucidware::core::FontFile::setFontWeight
        ),
        "forceAutohinter", sol::property(
            &lucidware::core::FontFile::getForceAutohinter,
            &lucidware::core::FontFile::setForceAutohinter
        ),
        "generateMipmaps", sol::property(
            &lucidware::core::FontFile::getGenerateMipmaps,
            &lucidware::core::FontFile::setGenerateMipmaps
        ),
        "hinting", sol::property(
            &lucidware::core::FontFile::getHinting,
            &lucidware::core::FontFile::setHinting
        ),
        "msdfPixelRange", sol::property(
            &lucidware::core::FontFile::getMsdfPixelRange,
            &lucidware::core::FontFile::setMsdfPixelRange
        ),
        "msdfSize", sol::property(
            &lucidware::core::FontFile::getMsdfSize,
            &lucidware::core::FontFile::setMsdfSize
        ),
        "multichannelSignedDistanceField", sol::property(
            &lucidware::core::FontFile::getMultichannelSignedDistanceField,
            &lucidware::core::FontFile::setMultichannelSignedDistanceField
        ),
        "opentypeFeatureOverrides", sol::property(
            &lucidware::core::FontFile::getOpentypeFeatureOverrides,
            &lucidware::core::FontFile::setOpentypeFeatureOverrides
        ),
        "oversampling", sol::property(
            &lucidware::core::FontFile::getOversampling,
            &lucidware::core::FontFile::setOversampling
        ),
        "styleName", sol::property(
            &lucidware::core::FontFile::getStyleName,
            &lucidware::core::FontFile::setStyleName
        ),
        "subpixelPositioning", sol::property(
            &lucidware::core::FontFile::getSubpixelPositioning,
            &lucidware::core::FontFile::setSubpixelPositioning
        ),
        "clearCache", &lucidware::core::FontFile::clearCache,
        "clearGlyphs", &lucidware::core::FontFile::clearGlyphs,
        "clearKerningMap", &lucidware::core::FontFile::clearKerningMap,
        "getFallbacks", &lucidware::core::FontFile::getFallbacks,
        "getFaceIndex", &lucidware::core::FontFile::getFaceIndex,
        "getFontName", &lucidware::core::FontFile::getFontName,
        "getGlyphAdvance", &lucidware::core::FontFile::getGlyphAdvance,
        "getGlyphIndex", &lucidware::core::FontFile::getGlyphIndex,
        "getGlyphList", &lucidware::core::FontFile::getGlyphList,
        "getGlyphOffset", &lucidware::core::FontFile::getGlyphOffset,
        "getGlyphSize", &lucidware::core::FontFile::getGlyphSize,
        "getKerning", &lucidware::core::FontFile::getKerning,
        "getKerningList", &lucidware::core::FontFile::getKerningList,
        "getLanguageSupportOverride", &lucidware::core::FontFile::getLanguageSupportOverride,
        "getScriptSupportOverride", &lucidware::core::FontFile::getScriptSupportOverride,
        "getMsdfPixelRange", &lucidware::core::FontFile::getMsdfPixelRange,
        "getMsdfSize", &lucidware::core::FontFile::getMsdfSize,
        "getOversampling", &lucidware::core::FontFile::getOversampling,
        "getSizeCacheList", &lucidware::core::FontFile::getSizeCacheList,
        "getTextureCount", &lucidware::core::FontFile::getTextureCount,
        "getTextureImage", &lucidware::core::FontFile::getTextureImage,
        "getTextureOffsets", &lucidware::core::FontFile::getTextureOffsets,
        "getTransform", &lucidware::core::FontFile::getTransform,
        "getVariationCoordinates", &lucidware::core::FontFile::getVariationCoordinates,
        "isLanguageSupported", &lucidware::core::FontFile::isLanguageSupported,
        "isScriptSupported", &lucidware::core::FontFile::isScriptSupported,
        "loadBitmapFont", &lucidware::core::FontFile::loadBitmapFont,
        "loadDynamicFont", &lucidware::core::FontFile::loadDynamicFont,
        "setCacheCapacity", &lucidware::core::FontFile::setCacheCapacity,
        "setFallbacks", &lucidware::core::FontFile::setFallbacks,
        "setFontName", &lucidware::core::FontFile::setFontName,
        "setFontStyle", &lucidware::core::FontFile::setFontStyle,
        "setFontWeight", &lucidware::core::FontFile::setFontWeight,
        "setGlyphAdvance", &lucidware::core::FontFile::setGlyphAdvance,
        "setGlyphOffset", &lucidware::core::FontFile::setGlyphOffset,
        "setGlyphSize", &lucidware::core::FontFile::setGlyphSize,
        "setGlyphTextureIndex", &lucidware::core::FontFile::setGlyphTextureIndex,
        "setGlyphUvRect", &lucidware::core::FontFile::setGlyphUvRect,
        "setKerning", &lucidware::core::FontFile::setKerning,
        "setLanguageSupportOverride", &lucidware::core::FontFile::setLanguageSupportOverride,
        "setScriptSupportOverride", &lucidware::core::FontFile::setScriptSupportOverride,
        "setTextureImage", &lucidware::core::FontFile::setTextureImage,
        "setTextureOffsets", &lucidware::core::FontFile::setTextureOffsets,
        "setTransform", &lucidware::core::FontFile::setTransform,
        "setVariationCoordinates", &lucidware::core::FontFile::setVariationCoordinates,
        "cast", [](Resource* instance) {
            return new FontFile(godot::Object::cast_to<GodotFontFile>(instance->getResource()));
        }
    );
}