package sunaba.core;

import haxe.ds.Vector;

@:native("Vector2")
extern class Vector2 {
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
    public function min(other : Vector2) : Vector2;
    public function max(other : Vector2) : Vector2;
    public function distanceTo(other : Vector2) : Float;
    public function distanceSquaredTo(other : Vector2) : Float;
    public function angleTo(other : Vector2) : Float;
    public function angleToPoint(other : Vector2) : Float;
    public function dot(other : Vector2) : Float;
    public function posmod(mod : Float) : Vector2;
    public function posmodv(other : Vector2) : Vector2;
    public function project(other : Vector2) : Vector2;
    public function planeProject(d : Float, vector : Vector2) : Vector2;
    public function lerp(to : Vector2, t : Float) : Vector2;
    public function slerp(to : Vector2, weight : Float) : Vector2;
    public function cubicInterpolate(b : Vector2, preA : Vector2, postB : Vector2, weight : Float) : Vector2;
    public function cubicInterpolateInTime(b : Vector2, preA : Vector2, postB : Vector2, weight : Float, bT : Float,  preAT : Float, postBT : Float) : Vector2;
    public function moveToward(to : Vector2, deltaTime : Float) : Vector2;
    public function slide(normal : Vector2) : Vector2;
    public function bounce(normal : Vector2) : Vector2;
    public function reflect(normal : Vector2) : Vector2;
    public function isEqualApprox(v : Vector2) : Bool;
    public function isZeroApprox() : Bool;
    public function angle() : Float;
    public function abs() : Vector2;
    public function rotated(by: Float) : Vector2;
    public function orthogonal() : Vector2;
    public function sign() : Vector2;
    public function floor() : Vector2;
    public function ceil() : Vector2;
    public function round() : Vector2;
    public function snap(by : Vector2) : Vector2;
    public function clamp(min : Vector2, max : Vector2) : Vector2;
    public function aspect() : Float;
    @:native("tostring")
    public function toString() : String;
}
