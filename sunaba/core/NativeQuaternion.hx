package sunaba.core;

@:native("Quaternion")
extern class NativeQuaternion {
    public var x : Float;
    public var y : Float;
    public var z : Float;
    public var w : Float;
    public function new(x : Float, y : Float, z : Float, w : Float);
    @:native("new")
    public static function zero() : Quaternion;
    public function angleTo(quat : NativeQuaternion) : Float;
    public function dot(q : NativeQuaternion) : Float;
    public function exp() : Quaternion;
    public function inverse() : Quaternion;
    public function isEqualApprox(quat : NativeQuaternion) : Bool;
    public function isNormalized() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function log();
    public function normalized() : Quaternion;
    public function slerp(to : NativeQuaternion, weight : Float) : Quaternion;
    public function sphericalCubicInterpolate(b : NativeQuaternion, preA : NativeQuaternion, postB : NativeQuaternion, weight : Float) : Quaternion;
    public function sphericalCubicInterpolateInTime(b : NativeQuaternion, preA : NativeQuaternion, postB : NativeQuaternion, weight : Float, bT : Float, preAT : Float, postBT : Float) : Quaternion;
    @:native("tostring")
    public function toString() : String;
}