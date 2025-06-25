package lucidfx.core;

@:native("Color")
extern class Color {
    public var r : Float;
    public var g : Float;
    public var b : Float;
    public var a : Float;
    public function new();
    @:native("new")
    public static function rgba(r : Float, g : Float, b : Float, a : Float): Color;
    @:native("new")
    public static function rgb(r : Float, g : Float, b : Float): Color;
    @:native("new")
    public static function fromColorAndAlpha(color : Color, a : Float): Color;
    @:native("new")
    public static function code(code : String, a : Float = 1.0): Color;
    public function blend(ove : Color) : Color;
    public function clamp(min : Color = null, max : Color = null) : Color;
    public function darkened(amount : Float) : Color;
    @:native("fromHSV")
    public static function hsv(h : Float, s : Float, v : Float, alpha : Float = 1.0) : Color;
    @:native("fromRGBE9995")
    public static function rgbe9995(r : Float, g : Float, b : Float, e : Float, alpha : Float = 1.0) : Color;
    @:native("fromString")
    public static function string(str: String, defalt : Color) : Color;
    public function getLuminance() : Float;
    public static function hex(hex : Int) : Color;
    public static function hex64(hex : Int) : Color;
    public static function html(html : String) : Color;
    public static function htmlIsValid(html : String) : Bool;
    public function inverted() : Color;
    public function isEqualApprox(to : Color) : Bool;
    public function lerp(to : Color, weight : Float) : Color;
    public function lightened(amount : Float) : Color;
    public function linearToSrgb() : Color;
    public function srgbToLinear() : Color;
    public function toAbgr32() : Int;
    public function toAbgr64() : Int;
    public function toArgb32() : Int;
    public function toArgb64() : Int;
    public function toHtml() : String;
    public function toRgba32() : Int;
    public function toRgba64() : Int;
}