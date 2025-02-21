package sunaba.core;

import haxe.ds.Vector;

@:native("Vector2")
extern class NativeVector2 {
    public var x : Float;
    public var y : Float;
    public function new(x : Float = 0, y : Float = 0);
    @:native("new")
    public static function zero() : Vector2;
    public function normalize() : Void;
    public function normalized() : Vector2;
    public function isNormalized() : Bool;
    public function length() : Float;
    public function lengthSquared() : Float;
    public function limitLength(maxLength : Float) : Void;
    public function min(other : NativeVector2) : Vector2;
    public function max(other : NativeVector2) : Vector2;
    public function distanceTo(other : NativeVector2) : Float;
    public function distanceSquaredTo(other : NativeVector2) : Float;
    public function angleTo(other : NativeVector2) : Float;
    public function angleToPoint(other : NativeVector2) : Float;
    public function dot(other : NativeVector2) : Float;
    public function posmod(mod : Float) : Vector2;
    public function posmodv(other : NativeVector2) : Vector2;
    public function project(other : NativeVector2) : Vector2;
    public function planeProject(d : Float, vector : NativeVector2) : Vector2;
    public function lerp(to : NativeVector2, t : Float) : Vector2;
    public function slerp(to : NativeVector2, weight : Float) : Vector2;
    public function cubicInterpolate(b : NativeVector2, preA : NativeVector2, postB : NativeVector2, weight : Float) : Vector2;
    public function cubicInterpolateInTime(b : NativeVector2, preA : NativeVector2, postB : NativeVector2, weight : Float, bT : Float,  preAT : Float, postBT : Float) : Vector2;
    public function moveToward(to : NativeVector2, deltaTime : Float) : Vector2;
    public function slide(normal : NativeVector2) : Vector2;
    public function bounce(normal : NativeVector2) : Vector2;
    public function reflect(normal : NativeVector2) : Vector2;
    public function isEqualApprox(v : NativeVector2) : Bool;
    public function isZeroApprox() : Bool;
    public function angle() : Float;
    public function abs() : Vector2;
    public function rotated(by, Float) : Vector2;
    public function orthogonal() : Vector2;
    public function sign() : Vector2;
    public function floor() : Vector2;
    public function ceil() : Vector2;
    public function round() : Vector2;
    public function snap(by : NativeVector2) : Vector2;
    public function clamp(min : NativeVector2, max : NativeVector2) : Vector2;
    public function aspect() : Float;
    @:native("tostring")
    public function toString() : String;
}
