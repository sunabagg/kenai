package sunaba.core;

@:native("Transform3D")
extern class Transform3D {
    public var basis : Basis;
    public var origin : Vector3;
    public function new(basis : NativeBasis, origin : NativeVector3);
    @:native("new")
    public static function zero() : Transform3D;
    public function affineInverse() : Transform3D;
    public function interpolateWith(tform : Transform3D, c : Float) : Transform3D;
    public function isEqualApprox(tform : Transform3D) : Bool;
    public function lookingAt(target : NativeVector3, up : NativeVector3) : Transform3D;
    public function orthonormalized() : Transform3D;
    public function rotated(axis : NativeVector3, angle : Float) : Transform3D;
    public function rotatedLocal(axis : NativeVector3, angle : Float) : Transform3D;
    public function scaled(scale : NativeVector3) : Transform3D;
    public function scaledLocal(scale : NativeVector3) : Transform3D;
    public function translated(translation : NativeVector3) : Transform3D;
    public function translatedLocal(translation : NativeVector3) : Transform3D;
    @:native("tostring")
    public function toString() : String;
}