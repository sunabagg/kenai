package lucidware.core;

@:native("Basis")
extern class Basis {
    public var rows: lua.Table<Int, Vector3>;
    public function new(x : Vector3, y : Vector3, z : Vector3);
    @:native("new")
    public static function zero() : Basis;
    public function determinant() : Float;
    public function fromEuler(euler : Vector3, order : Int = 2) : Basis;
    public function fromScale(scale : Vector3) : Basis;
    public function getEuler(order : Int = 2) : Vector3;
    public function getRoationQuaternion() : Quaternion;
    public function getScale() : Vector3;
    public function inverse() : Basis;
    public function isEqualApprox(basis : Basis) : Bool;
    public function lookingAt(target : Vector3, up : Vector3) : Basis;
    public function orthonormalized() : Basis;
    public function scaled(scale : Vector3) : Basis;
    public function slerp(to : Basis, weight : Float) : Basis;
    public function tdotx(v : Vector3) : Float;
    public function tdoty(v : Vector3) : Float;
    public function tdotz(v : Vector3) : Float;
    public function transposed() : Basis;
    @:native("tostring")
    public function toString() : String;
}