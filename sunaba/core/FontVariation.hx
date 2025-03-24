package sunaba.core;

@:native("FontVariation")
extern class FontVariation extends Font {
    public var baseFont: Font;
    public var baselineOffset: Float;
    public var opentypeFeatures: Map<Any, Any>;
    public var spacingBottom : Int;
    public var spacingGlyph : Int;
    public var spacingSpace : Int;
    public var spacingTop : Int;
    public var variationEmbolden : Float;
    public var variationFaceIndex : Float;
    public var variationOpentype : Map<Any, Any>;
    public function setSpaing(spacing : Int, value : Int) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : FontVariation;
}

abstract FontVariationAbstract(FontVariation) from FontVariation to FontVariation {
    @:from
    public static function fromResource(resource: Resource) : FontVariationAbstract {
        var fontVar = FontVariation.castFrom(resource);
        if (fontVar.isNull()) {
            return null;
        }
        return fontVar;
    } 
}