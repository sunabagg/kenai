package lucidfx.core;

@:native("Transform3D")
extern class Transform3D {
    public var basis : Basis;
    public var origin : Vector3;
    public function new(basis : Basis, origin : Vector3);
    @:native("new")
    public static function zero() : Transform3D;
    public function affineInverse() : Transform3D;
    public function interpolateWith(tform : Transform3D, c : Float) : Transform3D;
    public function isEqualApprox(tform : Transform3D) : Bool;
    public function lookingAt(target : Vector3, up : Vector3) : Transform3D;
    public function orthonormalized() : Transform3D;
    public function rotated(axis : Vector3, angle : Float) : Transform3D;
    public function rotatedLocal(axis : Vector3, angle : Float) : Transform3D;
    public function scaled(scale : Vector3) : Transform3D;
    public function scaledLocal(scale : Vector3) : Transform3D;
    public function translated(translation : Vector3) : Transform3D;
    public function translatedLocal(translation : Vector3) : Transform3D;
    @:native("tostring")
    public function toString() : String;
}