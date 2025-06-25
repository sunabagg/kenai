package lucidware.spatial;

import lucidware.core.Vector3;
import lucidware.core.Transform3D;
import lucidware.core.Quaternion;
import lucidware.core.Vector3;
import lucidware.core.Basis;
import lucidware.core.Component;
import lucidware.core.Entity;

@:native("SpatialTransform")
extern class SpatialTransform extends Component {
    public var basis : Basis;
    public var position : Vector3;
    public var rotation : Vector3;
    public var rotationDegrees : Vector3;
    public var scale : Vector3;
    public var quaternion : Quaternion;
    public var rotationOrder : Int;
    public var globalPosition : Vector3;
    public var globalRotation : Vector3;
    public var globalRotationDegrees : Vector3;
    public var globalBasis : Basis;
    public var global : Transform3D;
    public var local : Transform3D;
    public function isTopLevel() : Bool;
    public function forceUpdate() : Void;
    public function getParent() : SpatialTransform;
    public function globalRotate(axis : Vector3, angle : Float) : Void;
    public function globalTranslate(translation : Vector3) : Void;
    public function globalScale(scale : Vector3) : Void;
    public function hide() : Void;
    public function isScaleDisabled() : Bool;
    public function isVisible() : Bool;
    public function lookAt(target : Vector3, up : Vector3, useModelFront : Bool = false) : Void;
    public function lookAtFromPosition(position : Vector3, target : Vector3, up : Vector3, useModelFront : Bool = false) : Void;
    public function orthonormalize() : Void;
    public function roate(axis : Vector3, angle : Float) : Void;
    public function rotateObjectLocal(axis : Vector3, angle : Float) : Void;
    public function rotateX(angle : Float) : Void;
    public function rotateY(angle : Float) : Void;
    public function rotateZ(angle : Float) : Void;
    public function scaleObjectLocal(scale : Vector3) : Void;
    public function setDisableScale(disable : Bool) : Void;
    public function setIdentity() : Void;
    public function show() : Void;
    public function toGlobal(position : Vector3) : Vector3;
    public function toLocal(position : Vector3) : Vector3;
    public function translate(offset : Vector3) : Void;
    public function translateObjectLocal(offset : Vector3) : Void;
    public static function getFromEntity(entity : Entity) : SpatialTransform;
}