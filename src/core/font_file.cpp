#include "font_file.h"

void kenai::core::bindFontFile(sol::state &lua) {
    lua.new_usertype<kenai::core::FontFile>("FontFile",
        "new", sol::factories(
            []() { return new kenai::core::FontFile(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Font>(),

        "allowSystemFallback", sol::property(
            &kenai::core::FontFile::getAllowSystemFallback,
            &kenai::core::FontFile::setAllowSystemFallback
        ),
        "antialiasing", sol::property(
            &kenai::core::FontFile::getAntialiasing,
            &kenai::core::FontFile::setAntialiasing
        ),
        "data", sol::property(
            &kenai::core::FontFile::getData,
            &kenai::core::FontFile::setData
        ),
        "disableEmbeddedBitmaps", sol::property(
            &kenai::core::FontFile::getDisableEmbeddedBitmaps,
            &kenai::core::FontFile::setDisableEmbeddedBitmaps
        ),
        "fixedSize", sol::property(
            &kenai::core::FontFile::getFixedSize,
            &kenai::core::FontFile::setFixedSize
        ),
        "fixedSizeScaleMode", sol::property(
            &kenai::core::FontFile::getFixedSizeScaleMode,
            &kenai::core::FontFile::setFixedSizeScaleMode
        ),
        "fontName", sol::property(
            &kenai::core::FontFile::getFontName,
            &kenai::core::FontFile::setFontName
        ),
        "fontStretch", sol::property(
            &kenai::core::FontFile::getFontStretch,
            &kenai::core::FontFile::setFontStretch
        ),
        "fontStyle", sol::property(
            &kenai::core::FontFile::getFontStyle,
            &kenai::core::FontFile::setFontStyle
        ),
        "fontWeight", sol::property(
            &kenai::core::FontFile::getFontWeight,
            &kenai::core::FontFile::setFontWeight
        ),
        "forceAutohinter", sol::property(
            &kenai::core::FontFile::getForceAutohinter,
            &kenai::core::FontFile::setForceAutohinter
        ),
        "generateMipmaps", sol::property(
            &kenai::core::FontFile::getGenerateMipmaps,
            &kenai::core::FontFile::setGenerateMipmaps
        ),
        "hinting", sol::property(
            &kenai::core::FontFile::getHinting,
            &kenai::core::FontFile::setHinting
        ),
        "msdfPixelRange", sol::property(
            &kenai::core::FontFile::getMsdfPixelRange,
            &kenai::core::FontFile::setMsdfPixelRange
        ),
        "msdfSize", sol::property(
            &kenai::core::FontFile::getMsdfSize,
            &kenai::core::FontFile::setMsdfSize
        ),
        "multichannelSignedDistanceField", sol::property(
            &kenai::core::FontFile::getMultichannelSignedDistanceField,
            &kenai::core::FontFile::setMultichannelSignedDistanceField
        ),
        "opentypeFeatureOverrides", sol::property(
            &kenai::core::FontFile::getOpentypeFeatureOverrides,
            &kenai::core::FontFile::setOpentypeFeatureOverrides
        ),
        "oversampling", sol::property(
            &kenai::core::FontFile::getOversampling,
            &kenai::core::FontFile::setOversampling
        ),
        "styleName", sol::property(
            &kenai::core::FontFile::getStyleName,
            &kenai::core::FontFile::setStyleName
        ),
        "subpixelPositioning", sol::property(
            &kenai::core::FontFile::getSubpixelPositioning,
            &kenai::core::FontFile::setSubpixelPositioning
        ),
        "clearCache", &kenai::core::FontFile::clearCache,
        "clearGlyphs", &kenai::core::FontFile::clearGlyphs,
        "clearKerningMap", &kenai::core::FontFile::clearKerningMap,
        "getFallbacks", &kenai::core::FontFile::getFallbacks,
        "getFaceIndex", &kenai::core::FontFile::getFaceIndex,
        "getFontName", &kenai::core::FontFile::getFontName,
        "getGlyphAdvance", &kenai::core::FontFile::getGlyphAdvance,
        "getGlyphIndex", &kenai::core::FontFile::getGlyphIndex,
        "getGlyphList", &kenai::core::FontFile::getGlyphList,
        "getGlyphOffset", &kenai::core::FontFile::getGlyphOffset,
        "getGlyphSize", &kenai::core::FontFile::getGlyphSize,
        "getKerning", &kenai::core::FontFile::getKerning,
        "getKerningList", &kenai::core::FontFile::getKerningList,
        "getLanguageSupportOverride", &kenai::core::FontFile::getLanguageSupportOverride,
        "getScriptSupportOverride", &kenai::core::FontFile::getScriptSupportOverride,
        "getMsdfPixelRange", &kenai::core::FontFile::getMsdfPixelRange,
        "getMsdfSize", &kenai::core::FontFile::getMsdfSize,
        "getOversampling", &kenai::core::FontFile::getOversampling,
        "getSizeCacheList", &kenai::core::FontFile::getSizeCacheList,
        "getTextureCount", &kenai::core::FontFile::getTextureCount,
        "getTextureImage", &kenai::core::FontFile::getTextureImage,
        "getTextureOffsets", &kenai::core::FontFile::getTextureOffsets,
        "getTransform", &kenai::core::FontFile::getTransform,
        "getVariationCoordinates", &kenai::core::FontFile::getVariationCoordinates,
        "isLanguageSupported", &kenai::core::FontFile::isLanguageSupported,
        "isScriptSupported", &kenai::core::FontFile::isScriptSupported,
        "loadBitmapFont", &kenai::core::FontFile::loadBitmapFont,
        "loadDynamicFont", &kenai::core::FontFile::loadDynamicFont,
        "setCacheCapacity", &kenai::core::FontFile::setCacheCapacity,
        "setFallbacks", &kenai::core::FontFile::setFallbacks,
        "setFontName", &kenai::core::FontFile::setFontName,
        "setFontStyle", &kenai::core::FontFile::setFontStyle,
        "setFontWeight", &kenai::core::FontFile::setFontWeight,
        "setGlyphAdvance", &kenai::core::FontFile::setGlyphAdvance,
        "setGlyphOffset", &kenai::core::FontFile::setGlyphOffset,
        "setGlyphSize", &kenai::core::FontFile::setGlyphSize,
        "setGlyphTextureIndex", &kenai::core::FontFile::setGlyphTextureIndex,
        "setGlyphUvRect", &kenai::core::FontFile::setGlyphUvRect,
        "setKerning", &kenai::core::FontFile::setKerning,
        "setLanguageSupportOverride", &kenai::core::FontFile::setLanguageSupportOverride,
        "setScriptSupportOverride", &kenai::core::FontFile::setScriptSupportOverride,
        "setTextureImage", &kenai::core::FontFile::setTextureImage,
        "setTextureOffsets", &kenai::core::FontFile::setTextureOffsets,
        "setTransform", &kenai::core::FontFile::setTransform,
        "setVariationCoordinates", &kenai::core::FontFile::setVariationCoordinates,
        "cast", [](Resource* instance) {
            return new FontFile(godot::Object::cast_to<GodotFontFile>(instance->getResource()));
        }
    );
}