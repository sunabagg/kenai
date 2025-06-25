package lucidfx.core;

@:native("Quaternion")
extern class Quaternion {
    public var x : Float;
    public var y : Float;
    public var z : Float;
    public var w : Float;
    public function new(x : Float, y : Float, z : Float, w : Float);
    @:native("new")
    public static function zero() : Quaternion;
    public function angleTo(quat : Quaternion) : Float;
    public function dot(q : Quaternion) : Float;
    public function exp() : Quaternion;
    public function inverse() : Quaternion;
    public function isEqualApprox(quat : Quaternion) : Bool;
    public function isNormalized() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function log() : Quaternion;
    public function normalized() : Quaternion;
    public function slerp(to : Quaternion, weight : Float) : Quaternion;
    public function sphericalCubicInterpolate(b : Quaternion, preA : Quaternion, postB : Quaternion, weight : Float) : Quaternion;
    public function sphericalCubicInterpolateInTime(b : Quaternion, preA : Quaternion, postB : Quaternion, weight : Float, bT : Float, preAT : Float, postBT : Float) : Quaternion;
    @:native("tostring")
    public function toString() : String;
}