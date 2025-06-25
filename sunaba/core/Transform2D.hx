package lucidfx.core;

@:native("Transform2D")
extern class Transform2D {
    public var origin : Vector2;
    public var x : Vector2;
    public var y : Vector2;
    public function new(rotation : Float, position : Vector2);
    @:native("new")
    public static function zero() : Transform2D;
    @:native("new")
    public static function newWithScaleAndSkew(rotation: Float, scale: Vector2, skew: Float, position: Vector2) : Transform2D;
    @:native("new")
    public static function fromXYOrigin(x: Vector2, y: Vector2, origin: Vector2) : Transform2D;
    public function affineInverse() : Transform2D;
    public function basisXform(v: Vector2) : Vector2;
    public function basisXformInv(v: Vector2) : Vector2;
    public function determinant() : Float;
    public function getOrigin() : Vector2;
    public function getRotation() : Float;
    public function getScale() : Vector2;
    public function getSkew() : Float;
    public function interpolateWith(xform : Transform2D, weight : Float) : Transform2D;
    public function inverse() : Transform2D;
    public function isConformal() : Bool;
    public function isEqualApprox(xform : Transform2D) : Bool;
    public function isFinite() : Bool;
    public function lookingAt(?target : Vector2) : Transform2D;
    public function orthonormalized() : Transform2D;
    public function rotated(angle : Float) : Transform2D;
    public function rotatedLocal(angle: Float) : Transform2D;
    public function scaled(scale: Vector2): Transform2D;
    public function scaledLocal(scale: Vector2): Transform2D;
    public function translated(translation: Vector2): Transform2D;
    public function translatedLocal(translation: Vector2): Transform2D;
    @:native("tostring")
    public function toString() : String;
}