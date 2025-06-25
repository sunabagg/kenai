package sunaba.core;

@:native("SystemFont")
extern class SystemFont extends Font {
    public var allowSystemFallback: Bool;
    public var antialiasing: Bool;
    public var disableEmbeddedBitmaps: Bool;
    public var fontItalic: Bool;
    public var fontNames: lua.Table<Int, String>;
    public var fontStretch: Int;
    public var fontWeight: Int;
    public var forceAutohinter: Bool;
    public var generateMipmaps: Bool;
    public var hinting: Int;
    public var keepRoundingRemainders: Bool;
    public var msdfPixelRange: Int;
    public var msdfSize: Int;
    public var multichannelSignedDistanceField: Bool; 
    public var oversampling: Int;
    public var subpixelPositioning: Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic) : SystemFont;                               
}

abstract SystemFontAbstract(SystemFont) from SystemFont to SystemFont {
    @:from
    public static function fromResource(resource: Resource) : SystemFontAbstract {
        var systemFont = SystemFont.castFrom(resource);
        if (systemFont.isNull()) {
            return null;
        }
        return systemFont;
    } 
}