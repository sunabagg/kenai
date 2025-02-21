package sunaba.core;

@:native("Vector3")
extern class NativeVector3 {
    public var x : Float;
    public var y : Float;
    public var z : Float;
    public function new(x : Float, y : Float, z : Float);
    @:native("new")
    public static function zero() : Vector3;
    public function abs() : Vector3;
    public function angleTo(vector3 : NativeVector3) : Float;
    public function bezierInterpolate(control1 : NativeVector3, control2 : NativeVector3, end : NativeVector3, t : Float) : Vector3;
    public function bounce(normal : NativeVector3) : Vector3;
    public function ciel() : Vector3;
    public function clamp(min : NativeVector3, max : NativeVector3) : Vector3;
    public function cross(with : NativeVector3) : Vector3;
    public function cubicInterpolate(b : NativeVector3, preA : NativeVector3, postB : NativeVector3, weight : Float) : Vector3;
    public function cubicInterpolateInTime(b : NativeVector3, preA : NativeVector3, postB : NativeVector3, weight : Float, bT : Float, preAT : Float, postBT : Float) : Vector3;
    public function directionTo(to : NativeVector3) : Vector3;
    public function distanceTo(other : NativeVector3) : Float;
    public function distanceSquaredTo(other : NativeVector3) : Float;
    public function dot(other : NativeVector3) : Float;
    public function floor() : Vector3;
    public function inverse() : Vector3;
    public function isEqualApprox(v : NativeVector3) : Bool;
    public function isNormalized() : Vector3;
    public function isZeroApprox() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function limitLength(maxLength : Float) : Void;
    public function lerp(to : NativeVector3, weight : Float) : Vector3;
    public function max(other : NativeVector3) : Vector3;
    public function maxAxisIndex() : Int;
    public function min(other : NativeVector3) : Vector3;
    public function minAxisIndex() : Int;
    public function moveToward(to : NativeVector3, deltaTime : Float) : Vector3;
    public function normalize() : Void;
    public function normalized() : Vector3;
    public function octahedronDecode(oct : NativeVector2) : Vector3;
    public function octahedronEncode() : Vector2;
    public function posmod(mod : Float) : Vector3;
    public function posmodv(other : NativeVector3) : Vector3;
    public function project(other : NativeVector3) : Vector3;
    public function reflect(normal : NativeVector3) : Vector3;
    public function rotated(axis : NativeVector3, by : Float) : Vector3;
    public function round() : Vector3;
    public function sign() : Vector3;
    public function signedAngleTo(to : NativeVector3, axis : NativeVector3) : Float;
    public function slerp(to : NativeVector3, weight : Float) : Vector3;
    public function slide(normal : NativeVector3) : Vector3;
    public function snapped(val : NativeVector3) : Vector3;
    @:native("tostring")
    public function toString();
}