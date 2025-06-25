package lucidfx.core;

@:native("Rect2i")
extern class Rect2i {
    public var end : Vector2i;
    public var position : Vector2i;
    public var size : Vector2i;
    public function new();
    @:native("new")
    public static function fromVector2is(position : Vector2i, size : Vector2i) : Rect2i;
    @:native("new")
    public static function fromInts(x : Int, y : Int, width : Int, height : Int) : Rect2i;
    @:native("new")
    public static function fromRect2s(rect : Rect2) : Rect2i;
    public function abs() : Rect2i;
    public function encloses(rect : Rect2i) : Bool;
    public function expand(vector : Vector2i) : Rect2i;
    public function getArea() : Int;
    public function getCenter() : Vector2i;
    public function grow(amount : Int) : Rect2i;
    public function growIndividual(left : Int, top : Int, right : Int, bottom : Int) : Rect2i;
    public function growSide(side : Int, amount : Int) : Rect2i;
    public function hasArea() : Bool;
    public function hasPoint(point : Vector2i) : Bool;
    public function intersetion(rect : Rect2i) : Rect2i;
    public function intersects(rect : Rect2i, includeBorders : Bool = false) : Bool;
    @:native("tostring")
    public function toString() : String;
}