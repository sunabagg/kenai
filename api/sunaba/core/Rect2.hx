package sunaba.core;

@:native("Rect2")
extern class Rect2 {
    public var end : Vector2;
    public var position : Vector2;
    public var size : Vector2;
    public function new();
    @:native("new")
    public static function fromVector2s(position : Vector2, size : Vector2) : Rect2;
    @:native("new")
    public static function fromFloats(x : Float, y : Float, width : Float, height : Float) : Rect2;
    @:native("new")
    public static function fromRect2is(rect : Rect2i) : Rect2;
    public function abs() : Rect2;
    public function encloses(rect : Rect2) : Bool;
    public function expand(vector : Vector2) : Rect2;
    public function getArea() : Float;
    public function getCenter() : Vector2;
    public function grow(amount : Float) : Rect2;
    public function growIndividual(left : Float, top : Float, right : Float, bottom : Float) : Rect2;
    public function growSide(side : Int, amount : Float) : Rect2;
    public function hasArea() : Bool;
    public function hasPoint(point : Vector2) : Bool;
    public function intersetion(rect : Rect2) : Rect2;
    public function intersects(rect : Rect2, includeBorders : Bool = false) : Bool;
    public function isEqualApprox(rect : Rect2) : Bool;
    public function merge(rect : Rect2) : Rect2;
    @:native("tostring")
    public function toString() : String;
}