package lucidware.spatial;

import lucidware.core.Vector2;
import lucidware.core.Vector3;
import lucidware.core.Component;
import lucidware.core.Vector2;
import lucidware.core.Vector3;

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
    public function isPositionBehind(position : Vector3) : Bool;
    public function makeCurrent() : Void;
    public function projectLocalRayNormal(screenPoint : Vector2) : Vector3;
    public function projectPosition(screenPoint : Vector2, zDepth : Float) : Vector3;
    public function projectRayNormal(screenPoint : Vector2) : Vector3;
    public function projectRayOrigin(screenPoint : Vector2) : Vector3;
    public function setCullMaskValue(index : Int, value : Bool) : Void;
    public function setFrustum(size : Float, offset : Vector2, zNear : Float, zFar : Float) : Void;
    public function setOrthagonal(size : Float, zNear : Float, zFar : Float) : Void;
    public function setPerspective(fov : Float, zNear : Float, zFar : Float) : Void;
    public function unprojectPosition(position : Vector3) : Vector2;
    public static function getFromEntity(entity : lucidware.core.Entity) : Camera;
}