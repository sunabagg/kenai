package lucidfx.core;

@:native("Font")
extern class Font extends Resource {
    public var fallbacks: lua.Table<Int, Font>;
    public function getAscent(fontSize : Int) : Float;
    public function getCharSize(chr : Int, fontsize : Int) : Vector2;
    public function getDescent(fontSize : Int) : Float;
    public function getFaceCount() : Int;
    public function getFontName() : String;
    public function getFontStyle() : Int;
    public function getFontWeight() : Int;
    public function getHeight(fontSize : Int) : Float;
    public function getMultilineStringSize(text : String, alignment : Float = 0.0, width : Float = -1.0, fontSize : Float = 16, maxLines: Int = -1, brkFlags : Int = 3, justificationFlags : Int = 3, direction : Int = 0, orientation : Int = 0) : Vector2;
    public function getOpentypeFeatures() : Dictionary;
    public function getOtNameStrings() : Dictionary;
    public function getSpacing(spacing : Int) : Int;
    public function getStringSize(text : String, alignment : Int = 0, width : Float = 0, fontSize : Int = 16, justificationFlags : Int = 3, direction : Int = 0, orientation : Int = 0) : Vector2;
    public function getSupportedChars() : String;
    public function getSupportedFeatureList() : Dictionary;
    public function getSupportedVariationList() : Dictionary;
    public function getUnderlinePosition(fontSize : Int) : Float;
    public function getUnderlineThickness(fontSize : Int) : Float;
    public function hasChar(chr : Int) : Bool;
    public function isLanguageSupported(lang : String) : Bool;
    public function isScriptSupported(script : String) : Bool;
    public function setCacheCapacity(singleline : Int, multiline : Int) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Font;
}

abstract FontAbstract(Font) from Font to Font {
    @:from
    public static function fromResource(resource : Resource) : FontAbstract {
        var font = Font.castFrom(resource);
        if (font.isNull()) {
            return null;
        }
        return font;
    } 
}