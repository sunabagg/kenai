package sunaba.spatial;

import sunaba.core.BaseObject;
import sunaba.core.NativeVector3;
import sunaba.core.Transform3D;
import sunaba.core.Quaternion;
import sunaba.core.Vector3;
import sunaba.core.Basis;
import sunaba.core.Component;
import sunaba.core.Entity;
import sunaba.native.spatial.SpatialTransformNative;

class SpatialTransform extends Component {
    var stInstance(get, default): SpatialTransformNative;
    function get_stInstance(): SpatialTransformNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new SpatialTransformNative();
        if (instance == null) {
            throw "SpatialTransform.new() returned null";
        }
        stInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance: SpatialTransformNative): SpatialTransform {
        if (instance == null) {
            throw "SpatialTransform.fromInstance() received null instance";
        }
        var obj = new SpatialTransform();
        obj.instance = instance;
        return obj;
    }

    public var basis(get, set): Basis;
    public function get_basis(): Basis {
        return stInstance.basis;
    }
    public function set_basis(value: Basis): Void {
        stInstance.basis = value;
    }

    public var position(get, set): Vector3;
    public function get_position(): Vector3 {
        return stInstance.position;
    }
    public function set_position(value: Vector3): Void {
        stInstance.position = value;
    }

    public var rotation(get, set): Vector3;
    public function get_rotation(): Vector3 {
        return stInstance.rotation;
    }
    public function set_rotation(value: Vector3): Void {
        stInstance.rotation = value;
    }

    public var rotationDegrees(get, set): Vector3;
    public function get_rotationDegrees(): Vector3 {
        return stInstance.rotationDegrees;
    }
    public function set_rotationDegrees(value: Vector3): Void {
        stInstance.rotationDegrees = value;
    }

    public var scale(get, set): Vector3;
    public function get_scale(): Vector3 {
        return stInstance.scale;
    }
    public function set_scale(value: Vector3): Void {
        stInstance.scale = value;
    }

    public var quaternion(get, set): Quaternion;
    public function get_quaternion(): Quaternion {
        return stInstance.quaternion;
    }
    public function set_quaternion(value: Quaternion): Void {
        stInstance.quaternion = value;
    }

    public var rotationOrder(get, set): Int;
    public function get_rotationOrder(): Int {
        return stInstance.rotationOrder;
    }
    public function set_rotationOrder(value: Int): Void {
        stInstance.rotationOrder = value;
    }

    public var globalPosition(get, set): Vector3;
    public function get_globalPosition(): Vector3 {
        return stInstance.globalPosition;
    }
    public function set_globalPosition(pos: Vector3): Void {
        stInstance.globalPosition = pos;
    }

    public var globalRotation(get, set): Vector3;
    public function get_globalRotation(): Vector3 {
        return stInstance.globalRotation;
    }
    public function set_globalRotation(rot: Vector3): Void {
        stInstance.globalRotation = rot;
    }

    public var globalRotationDegrees(get, set): Vector3;
    public function get_globalRotationDegrees(): Vector3 {
        return stInstance.globalRotationDegrees;
    }
    public function set_globalRotationDegrees(rot: Vector3): Void {
        stInstance.globalRotationDegrees = rot;
    }

    public var globalBasis(get, set): Basis;
    public function get_globalBasis(): Basis {
        return stInstance.globalBasis;
    }
    public function set_globalBasis(basis: Basis): Void {
        stInstance.globalBasis = basis;
    }

    public var global(get, set): Transform3D;
    public function get_global(): Transform3D {
        return stInstance.global;
    }
    public function set_global(value: Transform3D): Void {
        stInstance.global = value;
    }

    public var local(get, set): Transform3D;
    public function get_local(): Transform3D {
        return stInstance.local;
    }
    public function set_local(value: Transform3D): Void {
        stInstance.local = value;
    }

    public function isTopLevel(): Bool {
        return stInstance.isTopLevel();
    }

    public function forceUpdate(): Void {
        stInstance.forceUpdate();
    }

    public function getParent(): SpatialTransform {
        return SpatialTransform.fromInstance(stInstance.getParent());
    }

    public function globalRotate(axis: NativeVector3, angle: Float): Void {
        stInstance.globalRotate(axis, angle);
    }

    public function globalTranslate(translation: Vector3): Void {
        stInstance.globalTranslate(translation);
    }

    public function globalScale(scale: NativeVector3): Void {
        stInstance.globalScale(scale);
    }

    public function hide(): Void {
        stInstance.hide();
    }

    public function isScaleDisabled(): Bool {
        return stInstance.isScaleDisabled();
    }

    public function isVisible(): Bool {
        return stInstance.isVisible();
    }

    public function lookAt(target: NativeVector3, up: NativeVector3, useModelFront: Bool = false): Void {
        stInstance.lookAt(target, up, useModelFront);
    }

    public function lookAtFromPosition(position: NativeVector3, target: NativeVector3, up: NativeVector3, useModelFront: Bool = false): Void {
        stInstance.lookAtFromPosition(position, target, up, useModelFront);
    }

    public function orthonormalize(): Void {
        stInstance.orthonormalize();
    }

    public function rotate(axis: NativeVector3, angle: Float): Void {
        stInstance.rotate(axis, angle);
    }

    public function rotateObjectLocal(axis: NativeVector3, angle: Float): Void {
        stInstance.rotateObjectLocal(axis, angle);
    }

    public function rotateX(angle: Float): Void {
        stInstance.rotateX(angle);
    }

    public function rotateY(angle: Float): Void {
        stInstance.rotateY(angle);
    }

    public function rotateZ(angle: Float): Void {
        stInstance.rotateZ(angle);
    }

    public function scaleObjectLocal(scale: NativeVector3): Void {
        stInstance.scaleObjectLocal(scale);
    }

    public function setDisableScale(disable: Bool): Void {
        stInstance.setDisableScale(disable);
    }

    public function setIdentity(): Void {
        stInstance.setIdentity();
    }

    public function show(): Void {
        stInstance.show();
    }

    public function toGlobal(position: NativeVector3): NativeVector3 {
        return stInstance.toGlobal(position);
    }

    public function toLocal(position: NativeVector3): NativeVector3 {
        return stInstance.toLocal(position);
    }

    public function translate(offset: NativeVector3): Void {
        stInstance.translate(offset);
    }

    public function translateObjectLocal(offset: NativeVector3): Void {
        stInstance.translateObjectLocal(offset);
    }
}

abstract SpatialTransformAbstract(SpatialTransform) from SpatialTransform to SpatialTransform {
    @:from
    public static function fromBaseObject(baseObj : BaseObject) : SpatialTransformAbstract {
        return SpatialTransform.fromInstance(cast baseObj.instance);
    }

    @:from
    public static function fromInstance(instance : SpatialTransformNative) : SpatialTransformAbstract {
        return SpatialTransform.fromInstance(instance);
    }
}