package lucidware.core;

@:native("Vector2i")
extern class Vector2i {
    public var x : Int;
    public var y : Int;
    public function new(x : Int, y : Int);
    @:native("new")
    public static function zero() : Vector2i;
    public function abs() : Vector2i;
    public function aspect() : Float;
    public function clamp(min : Vector2i, max : Vector2i) : Vector2i;
    public function length() : Float;
    public function lengthSquared() : Int;
    public function max(vector2i : Vector2i) : Vector2i;
    public function maxAxisIndex() : Int;
    public function min(vector2i : Vector2i) : Vector2i;
    public function minAxisIndex() : Int;
    public function sign() : Vector2i;
    @:native("tostring")
    public function toString(): String;
}