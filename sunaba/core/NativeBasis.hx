package sunaba.core;

@:native("Basis")
extern class NativeBasis {
    public var rows: lua.Table<Int, Vector3>;
    public function new(x : NativeVector3, y : NativeVector3, z : NativeVector3);
    @:native("new")
    public static function zero() : Basis;
    public function determinant() : Float;
    public function fromEuler(euler : NativeVector3, order : Int = 2) : Basis;
    public function fromScale(scale : NativeVector3) : Basis;
    public function getEuler(order : Int = 2) : Vector3;
    public function getRoationQuaternion() : Quaternion;
    public function getScale() : Vector3;
    public function inverse() : Basis;
    public function isEqualApprox(basis : Basis) : Bool;
    public function lookingAt(target : NativeVector3, up : NativeVector3 = new Vector3(0, 1, 0)) : Basis;
    public function orthonormalized() : Basis;
    public function scaled(scale : NativeVector3) : Basis;
    public function slerp(to : Basis, weight : Float) : Basis;
    public function tdotx(v : NativeVector3) : Float;
    public function tdoty(v : NativeVector3) : Float;
    public function tdotz(v : NativeVector3) : Float;
    public function transposed() : Basis;
    @:native("tostring")
    public function toString() : String;
}