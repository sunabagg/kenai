package sunaba.core;

@:native("Vector3i")
extern class NativeVector3i {
    public var x : Int;
    public var y : Int;
    public var z : Int;
    public function new(x : Int, y : Int, z : Int);
    @:native("new")
    public static function zero() : Vector3i;
    public function abs() : Vector3i;
    public function clamp(min : NativeVector3i, max : NativeVector3i) : Vector3i;
    public function length() : Float;
    public function lengthSquared() : Int;
    public function max(vector3i : NativeVector3i) : Vector3i;
    public function maxAxisIndex() : Int;
    public function min(vector3i : NativeVector3i) : Vector3i;
    public function minAxisIndex() : Int;
    public function sign() : Vector3i;
    @:native("tostring")
    public function toString() : String;
}