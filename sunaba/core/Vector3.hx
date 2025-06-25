package lucidware.core;

@:native("Vector3")
extern class Vector3 {
    public var x : Float;
    public var y : Float;
    public var z : Float;
    public function new(x : Float, y : Float, z : Float);
    @:native("new")
    public static function zero() : Vector3;
    public function abs() : Vector3;
    public function angleTo(vector3 : Vector3) : Float;
    public function bezierInterpolate(control1 : Vector3, control2 : Vector3, end : Vector3, t : Float) : Vector3;
    public function bounce(normal : Vector3) : Vector3;
    public function ciel() : Vector3;
    public function clamp(min : Vector3, max : Vector3) : Vector3;
    public function cross(with : Vector3) : Vector3;
    public function cubicInterpolate(b : Vector3, preA : Vector3, postB : Vector3, weight : Float) : Vector3;
    public function cubicInterpolateInTime(b : Vector3, preA : Vector3, postB : Vector3, weight : Float, bT : Float, preAT : Float, postBT : Float) : Vector3;
    public function directionTo(to : Vector3) : Vector3;
    public function distanceTo(other : Vector3) : Float;
    public function distanceSquaredTo(other : Vector3) : Float;
    public function dot(other : Vector3) : Float;
    public function floor() : Vector3;
    public function inverse() : Vector3;
    public function isEqualApprox(v : Vector3) : Bool;
    public function isNormalized() : Vector3;
    public function isZeroApprox() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function limitLength(maxLength : Float) : Void;
    public function lerp(to : Vector3, weight : Float) : Vector3;
    public function max(other : Vector3) : Vector3;
    public function maxAxisIndex() : Int;
    public function min(other : Vector3) : Vector3;
    public function minAxisIndex() : Int;
    public function moveToward(to : Vector3, deltaTime : Float) : Vector3;
    public function normalize() : Void;
    public function normalized() : Vector3;
    public function octahedronDecode(oct : Vector2) : Vector3;
    public function octahedronEncode() : Vector2;
    public function posmod(mod : Float) : Vector3;
    public function posmodv(other : Vector3) : Vector3;
    public function project(other : Vector3) : Vector3;
    public function reflect(normal : Vector3) : Vector3;
    public function rotated(axis : Vector3, by : Float) : Vector3;
    public function round() : Vector3;
    public function sign() : Vector3;
    public function signedAngleTo(to : Vector3, axis : Vector3) : Float;
    public function slerp(to : Vector3, weight : Float) : Vector3;
    public function slide(normal : Vector3) : Vector3;
    public function snapped(val : Vector3) : Vector3;
    @:native("tostring")
    public function toString() : String;
}