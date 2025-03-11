package sunaba.core;

@:native("Vector4")
extern class NativeVector4 {
    public var x : Float;
    public var y : Float;
    public var z : Float;
    public var w : Float;
    public function new(x : Float, y : Float, z : Float, w : Float);
    @:native("new")
    public static function zero() : Vector4;
    public function abs() : Vector4;
    public function ceil() : Vector4;
    public function clamp(min : NativeVector4, max : NativeVector4) : Vector4;
    public function cubicInterpolate(v0 : NativeVector4, v1 : NativeVector4, v2 : NativeVector4, v3 : NativeVector4, t : Float) : Vector4;
    public function cubicInterpolateInTime(v0 : NativeVector4, v1 : NativeVector4, v2 : NativeVector4, v3 : NativeVector4, t : Float, v0T : Float, v1T : Float, v2T : Float, v3T : Float) : Vector4;
    public function directionTo(to : NativeVector4) : Vector4;
    public function distanceTo(other : NativeVector4) : Float;
    public function distanceSquaredTo(other : NativeVector4) : Float;
    public function dot(other : NativeVector4) : Float;
    public function floor() : Vector4;
    public function inverse() : Vector4;
    public function isEqualApprox(v : NativeVector4) : Bool;
    public function isNormalized() : Bool;
    public function isZeroApprox() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function lerp(to : NativeVector4, weight : Float) : Vector4;
    public function max(other : NativeVector4) : Vector4;
    public function maxAxisIndex() : Int;
    public function min(other : NativeVector4) : Vector4;
    public function minAxisIndex() : Int;
    public function normalized() : Vector4;
    public function posmod(mod : Float) : Vector4;
    public function posmodv(other : NativeVector4) : Vector4;
    public function round() : Vector4;
    public function sign() : Vector4;
    public function snapped(val : NativeVector4) : Vector4;
    @:native("tostring")
    public function toString() : String;
}