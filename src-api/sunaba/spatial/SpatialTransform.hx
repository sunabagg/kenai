package sunaba.spatial;

import sunaba.core.NativeVector3;
import sunaba.core.Transform3D;
import sunaba.core.Quaternion;
import sunaba.core.Vector3;
import sunaba.core.Basis;
import sunaba.core.Component;
import sunaba.core.Entity;

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
    public function globalRotate(axis : NativeVector3, angle : Float) : Void;
    public function globalTranslate(translation : Vector3) : Void;
    public function globalScale(scale : NativeVector3) : Void;
    public function hide() : Void;
    public function isScaleDisabled() : Bool;
    public function isVisible() : Bool;
    public function lookAt(target : NativeVector3, up : NativeVector3, useModelFront : Bool = false) : Void;
    public function lookAtFromPosition(position : NativeVector3, target : NativeVector3, up : NativeVector3, useModelFront : Bool = false) : Void;
    public function orthonormalize() : Void;
    public function roate(axis : NativeVector3, angle : Float) : Void;
    public function rotateObjectLocal(axis : NativeVector3, angle : Float) : Void;
    public function rotateX(angle : Float) : Void;
    public function rotateY(angle : Float) : Void;
    public function rotateZ(angle : Float) : Void;
    public function scaleObjectLocal(scale : NativeVector3) : Void;
    public function setDisableScale(disable : Bool) : Void;
    public function setIdentity() : Void;
    public function show() : Void;
    public function toGlobal(position : NativeVector3) : NativeVector3;
    public function toLocal(position : NativeVector3) : NativeVector3;
    public function translate(offset : NativeVector3) : Void;
    public function translateObjectLocal(offset : NativeVector3) : Void;
    public static function getFromEntity(entity : Entity) : SpatialTransform;
}