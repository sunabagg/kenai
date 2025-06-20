#include "font_file.h"

void sunaba::core::bindFontFile(sol::state &lua) {
    lua.new_usertype<sunaba::core::FontFile>("FontFile",
        "new", sol::factories(
            []() { return new sunaba::core::FontFile(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Font>(),

        "allowSystemFallback", sol::property(
            &sunaba::core::FontFile::getAllowSystemFallback,
            &sunaba::core::FontFile::setAllowSystemFallback
        ),
        "antialiasing", sol::property(
            &sunaba::core::FontFile::getAntialiasing,
            &sunaba::core::FontFile::setAntialiasing
        ),
        "data", sol::property(
            &sunaba::core::FontFile::getData,
            &sunaba::core::FontFile::setData
        ),
        "disableEmbeddedBitmaps", sol::property(
            &sunaba::core::FontFile::getDisableEmbeddedBitmaps,
            &sunaba::core::FontFile::setDisableEmbeddedBitmaps
        ),
        "fixedSize", sol::property(
            &sunaba::core::FontFile::getFixedSize,
            &sunaba::core::FontFile::setFixedSize
        ),
        "fixedSizeScaleMode", sol::property(
            &sunaba::core::FontFile::getFixedSizeScaleMode,
            &sunaba::core::FontFile::setFixedSizeScaleMode
        ),
        "fontName", sol::property(
            &sunaba::core::FontFile::getFontName,
            &sunaba::core::FontFile::setFontName
        ),
        "fontStretch", sol::property(
            &sunaba::core::FontFile::getFontStretch,
            &sunaba::core::FontFile::setFontStretch
        ),
        "fontStyle", sol::property(
            &sunaba::core::FontFile::getFontStyle,
            &sunaba::core::FontFile::setFontStyle
        ),
        "fontWeight", sol::property(
            &sunaba::core::FontFile::getFontWeight,
            &sunaba::core::FontFile::setFontWeight
        ),
        "forceAutohinter", sol::property(
            &sunaba::core::FontFile::getForceAutohinter,
            &sunaba::core::FontFile::setForceAutohinter
        ),
        "generateMipmaps", sol::property(
            &sunaba::core::FontFile::getGenerateMipmaps,
            &sunaba::core::FontFile::setGenerateMipmaps
        ),
        "hinting", sol::property(
            &sunaba::core::FontFile::getHinting,
            &sunaba::core::FontFile::setHinting
        ),
        "msdfPixelRange", sol::property(
            &sunaba::core::FontFile::getMsdfPixelRange,
            &sunaba::core::FontFile::setMsdfPixelRange
        ),
        "msdfSize", sol::property(
            &sunaba::core::FontFile::getMsdfSize,
            &sunaba::core::FontFile::setMsdfSize
        ),
        "multichannelSignedDistanceField", sol::property(
            &sunaba::core::FontFile::getMultichannelSignedDistanceField,
            &sunaba::core::FontFile::setMultichannelSignedDistanceField
        ),
        "opentypeFeatureOverrides", sol::property(
            &sunaba::core::FontFile::getOpentypeFeatureOverrides,
            &sunaba::core::FontFile::setOpentypeFeatureOverrides
        ),
        "oversampling", sol::property(
            &sunaba::core::FontFile::getOversampling,
            &sunaba::core::FontFile::setOversampling
        ),
        "styleName", sol::property(
            &sunaba::core::FontFile::getStyleName,
            &sunaba::core::FontFile::setStyleName
        ),
        "subpixelPositioning", sol::property(
            &sunaba::core::FontFile::getSubpixelPositioning,
            &sunaba::core::FontFile::setSubpixelPositioning
        ),
        "clearCache", &sunaba::core::FontFile::clearCache,
        "clearGlyphs", &sunaba::core::FontFile::clearGlyphs,
        "clearKerningMap", &sunaba::core::FontFile::clearKerningMap,
        "getFallbacks", &sunaba::core::FontFile::getFallbacks,
        "getFaceIndex", &sunaba::core::FontFile::getFaceIndex,
        "getFontName", &sunaba::core::FontFile::getFontName,
        "getGlyphAdvance", &sunaba::core::FontFile::getGlyphAdvance,
        "getGlyphIndex", &sunaba::core::FontFile::getGlyphIndex,
        "getGlyphList", &sunaba::core::FontFile::getGlyphList,
        "getGlyphOffset", &sunaba::core::FontFile::getGlyphOffset,
        "getGlyphSize", &sunaba::core::FontFile::getGlyphSize,
        "getKerning", &sunaba::core::FontFile::getKerning,
        "getKerningList", &sunaba::core::FontFile::getKerningList,
        "getLanguageSupportOverride", &sunaba::core::FontFile::getLanguageSupportOverride,
        "getScriptSupportOverride", &sunaba::core::FontFile::getScriptSupportOverride,
        "getMsdfPixelRange", &sunaba::core::FontFile::getMsdfPixelRange,
        "getMsdfSize", &sunaba::core::FontFile::getMsdfSize,
        "getOversampling", &sunaba::core::FontFile::getOversampling,
        "getSizeCacheList", &sunaba::core::FontFile::getSizeCacheList,
        "getTextureCount", &sunaba::core::FontFile::getTextureCount,
        "getTextureImage", &sunaba::core::FontFile::getTextureImage,
        "getTextureOffsets", &sunaba::core::FontFile::getTextureOffsets,
        "getTransform", &sunaba::core::FontFile::getTransform,
        "getVariationCoordinates", &sunaba::core::FontFile::getVariationCoordinates,
        "isLanguageSupported", &sunaba::core::FontFile::isLanguageSupported,
        "isScriptSupported", &sunaba::core::FontFile::isScriptSupported,
        "loadBitmapFont", &sunaba::core::FontFile::loadBitmapFont,
        "loadDynamicFont", &sunaba::core::FontFile::loadDynamicFont,
        "setCacheCapacity", &sunaba::core::FontFile::setCacheCapacity,
        "setFallbacks", &sunaba::core::FontFile::setFallbacks,
        "setFontName", &sunaba::core::FontFile::setFontName,
        "setFontStyle", &sunaba::core::FontFile::setFontStyle,
        "setFontWeight", &sunaba::core::FontFile::setFontWeight,
        "setGlyphAdvance", &sunaba::core::FontFile::setGlyphAdvance,
        "setGlyphOffset", &sunaba::core::FontFile::setGlyphOffset,
        "setGlyphSize", &sunaba::core::FontFile::setGlyphSize,
        "setGlyphTextureIndex", &sunaba::core::FontFile::setGlyphTextureIndex,
        "setGlyphUvRect", &sunaba::core::FontFile::setGlyphUvRect,
        "setKerning", &sunaba::core::FontFile::setKerning,
        "setLanguageSupportOverride", &sunaba::core::FontFile::setLanguageSupportOverride,
        "setScriptSupportOverride", &sunaba::core::FontFile::setScriptSupportOverride,
        "setTextureImage", &sunaba::core::FontFile::setTextureImage,
        "setTextureOffsets", &sunaba::core::FontFile::setTextureOffsets,
        "setTransform", &sunaba::core::FontFile::setTransform,
        "setVariationCoordinates", &sunaba::core::FontFile::setVariationCoordinates,
        "cast", [](Resource* instance) {
            return new FontFile(godot::Object::cast_to<GodotFontFile>(instance->getResource()));
        }
    );
}