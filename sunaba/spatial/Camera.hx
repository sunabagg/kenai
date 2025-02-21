package sunaba.spatial;

import sunaba.core.NativeVector2;
import sunaba.core.NativeVector3;
import sunaba.core.Component;
import sunaba.core.Vector2;
import sunaba.core.Vector3;

@:native("Camera")
extern class Camera extends Component {
    public var cullMask : Int;
    public var current : Bool;
    public var dopplerTracking : Int;
    public var far : Float;
    public var fov : Float;
    public var frustumOffset : Vector2;
    public var hOffset : Float;
    public var keepAspect : Float;
    public var near : Float;
    public var projection : Int;
    public var size : Float;
    public var vOffset : Float;
    public function clearCurrent() : Void;
    public function getCullMaskValue(index : Int) : Bool;
    //public function getFrustum() : lua.Table<Int, Plane>;
    public function isPositionBehind(position : NativeVector3) : Bool;
    public function makeCurrent() : Void;
    public function projectLocalRayNormal(screenPoint : NativeVector2) : Vector3;
    public function projectPosition(screenPoint : NativeVector2, zDepth : Float) : Vector3;
    public function projectRayNormal(screenPoint : NativeVector2) : Vector3;
    public function projectRayOrigin(screenPoint : NativeVector2) : Vector3;
    public function setCullMaskValue(index : Int, value : Bool) : Void;
    public function setFrustum(size : Float, offset : NativeVector2, zNear : Float, zFar : Float) : Void;
    public function setOrthagonal(size : Float, zNear : Float, zFar : Float) : Void;
    public function setPerspective(fov : Float, zNear : Float, zFar : Float) : Void;
    public function unprojectPosition(position : NativeVector3) : Vector2;
    public static function getFromEntity(entity : sunaba.core.Entity) : Camera;
}