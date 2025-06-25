package sunaba.core;

@:native("Vector4i")
extern class Vector4i {
    public var x : Int;
    public var y : Int;
    public var z : Int;
    public var w : Int;
    public function new(x : Int, y : Int, z : Int, w : Int);
    @:native("new")
    public static function zero() : Vector4i;
    public function abs() : Vector4i;
    public function clamp(min : Vector4i, max : Vector4i) : Vector4i;
    public function length() : Float;
    public function lengthSquared() : Int;
    public function max(vector4i : Vector4i) : Vector4i;
    public function maxAxisIndex() : Int;
    public function min(vector4i : Vector4i) : Vector4i;
    public function minAxisIndex() : Int;
    public function sign() : Vector4i;
    @:native("tostring")
    public function toString() : String;
}