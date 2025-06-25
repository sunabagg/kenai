package lucidware.core;

import lucidware.core.io.BinaryData;

@:native("FontFile")
extern class FontFile extends Font {
    public var allowSystemFallback: Bool;
    public var antialiasing: Bool;
    public var data : BinaryData;
    public var disableEmbeddedBitmaps: Bool;
    public var fixedSize: Bool;
    public var fixedSizeScaleMode: Int;
    public var fontName: String;
    public var fontStretch: Int;
    public var fontStyle: Int;
    public var fontWeight: Int;
    public var forceAutohinter: Bool;
    public var generateMipmaps: Bool;
    public var hinting: Int;
    public var msdfPixelRange: Int;
    public var msdfSize: Int;
    public var multichannelSignedDistanceField: Bool;
    public var opentypeFeatureOverrides: Dictionary;
    public var oversampling: Float;
    public var styleName: String;
    public var subpixelPositioning: Int;
    public function clearCache() : Void;
    public function clearGlyphs(cacheIndex : Int, size : Vector2i) : Void;
    public function clearKerningMap(cacheIndex: Int, size: Int) : Void;
    public function clearSizeCache(cacheIndex : Int) : Void;
    public function clearTextures(cacheIndex: Int, size: Vector2i) : Void;
    public function getCacheAscent(cacheIndex : Int, size : Int) : Float;
    public function getCacheCount() : Int;
    public function getCacheDescent(cacheIndex : Int, size : Int) : Float;
    public function getCacheScale(cacheIndex : Int, size : Int) : Float;
    public function getCacheUnderlinePosition(cacheIndex : Int, size : Int) : Float;
    public function getCacheUnderlineThickness(cacheIndex : Int, size : Int) : Float;
    public function getCharFromGlyphIndex(size : Int, glyphIndex : Int) : Int;
    public function getEmbolden(cacheIndex : Int) : Float;
    public function getExtraBaselineOffset(cacheIndex : Int) : Float;
    public function getExtraSpacing(cacheIndex : Int, spacing : Int) : Int;
    public function getFaceIndex(cacheIndex : Int) : Int;
    public function getGlyphAdvance(cacheIndex : Int, size : Int, glyphIndex : Int) : Vector2;
    public function getGlyphIndex(size : Int, chr : Int, variationSelecttor: Int) : Int;
    public function getGlyphList(cacheIndex : Int, size : Vector2i) : lua.Table<Int, Int>;
    public function getGlyphOffset(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Vector2;
    public function getGlyphSize(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Vector2;
    public function getGlyphTextureIndex(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Int;
    public function getGlyphUvRect(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Rect2;
    public function getKerning(cacheIndex : Int, size : Int, glyphPair : Vector2i) : Vector2;
    public function getKerningList(cacheIndex : Int, size : Vector2i) : lua.Table<Int, Vector2i>;
    public function getLanguageSupportOverride(lang : String) : Bool;
    public function getScriptSupportOverride(script : String) : Bool;
    public function getScriptSupportOverrides() : lua.Table<Int, String>;
    public function getSizeCacheList(cacheIndex: Int): lua.Table<Int, Vector2i>;
    public function getTextureCount(cacheIndex : Int, size : Vector2i) : Int;
    public function getTextureImage(cacheIndex : Int, size : Vector2i, textureIndex : Int) : Image;
    public function getVariationCoordinates(cacheIndex : Int) : Map<Any, Any>;
    public function loadBitmapFont(path : String) : Int;
    public function loadDynamicFont(path : String) : Int;
    public function removeCache(cacheIndex : Int) : Void;
    public function removeGlyphs(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Void;
    public function removeKerning(cacheIndex : Int, size : Int, glyphPair : Vector2i) : Void;
    public function removeLanguageSupportOverride(lang : String) : Void;
    public function removeScriptSupportOverride(script : String) : Void;
    public function removeSizeCache(cacheIndex : Int, size : Vector2i) : Void;
    public function removeTexture(cacheIndex : Int, size : Vector2i, textureIndex : Int) : Void;
    public function renderGlyph(cacheIndex : Int, size : Vector2i, glyphIndex : Int) : Void;
    public function renderRange(cacheIndex : Int, size : Vector2i, start : Int, end : Int) : Void;
    public function setCacheAscent(cacheIndex : Int, size : Int, ascent : Float) : Void;
    public function setCacheDescent(cacheIndex : Int, size : Int, descent : Float) : Void;
    public function setCacheScale(cacheIndex : Int, size : Int, scale : Float) : Void;
    public function setCacheUnderlinePosition(cacheIndex : Int, size : Int, underlinePosition : Float) : Void;
    public function setCacheUnderlineThickness(cacheIndex : Int, size : Int, underlineThickness : Float) : Void;
    public function setEmbolden(cacheIndex : Int, embolden : Float) : Void;
    public function setExtraBaselineOffset(cacheIndex : Int, offset : Float) : Void;
    public function setExtraSpacing(cacheIndex : Int, spacing : Int, value : Int) : Void;
    public function setFaceIndex(cacheIndex : Int, faceIndex : Int) : Void;
    public function setGlyphAdvance(cacheIndex : Int, size : Int, glyphIndex : Int, advance : Vector2) : Void;
    public function setGlyphOffset(cacheIndex : Int, size : Int, glyphIndex : Int, offset : Vector2) : Void;
    public function setGlyphSize(cacheIndex : Int, size : Vector2i, glyph : Int, glSize : Vector2) : Void;
    public function setGlyphTextureIndex(cacheIndex : Int, size : Vector2i, glyphIndex : Int, textureIndex : Int) : Void;
    public function setGlyphUvRect(cacheIndex : Int, size : Vector2i, glyphIndex : Int, uvRect : Rect2) : Void;
    public function setKerning(cacheIndex : Int, size : Int, glyphPair : Vector2i, kerning : Vector2) : Void;
    public function setLanguageSupportOverride(lang : String, supported : Bool) : Void;
    public function setScriptSupportOverride(script : String, supported : Bool) : Void;
    public function setTextureImage(cacheIndex : Int, size : Vector2i, textureIndex : Int, image : Image) : Void;
    public function setTextureOffsets(cacheIndex : Int, size : Vector2i, textureIndex : Int, offsets : lua.Table<Int, Vector2i>) : Void;
    public function setVariationCoordinates(cacheIndex : Int, coordinates : Dictionary) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : FontFile;
}

abstract FontFileAbstract(FontFile) from FontFile to FontFile {
    @:from
    public static function fromResource(resource : Resource) : FontFileAbstract {
        var font = FontFile.castFrom(resource);
        if (font.isNull()) {
            return null;
        }
        return font;
    } 
}