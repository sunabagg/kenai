package sunaba.spatial;

import sunaba.core.NativeVector2;
import sunaba.core.NativeVector3;
import sunaba.core.Component;
import sunaba.core.Vector2;
import sunaba.core.Vector3;
import sunaba.native.spatial.CameraNative;

class Camera extends Component {
    public var cameraInstance(get, default): CameraNative;
    public function get_cameraInstance(): CameraNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new CameraNative();
        if (instance == null) {
            throw "Camera.new() returned null";
        }
        var type = Type.getClass(this);
        if (type == null) {
            throw "Behavior must be a class";
        }
        cameraInstance.setScriptType(type);

        cameraInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance: CameraNative): Camera {
        if (instance == null) {
            throw "Camera.fromInstance() received null instance";
        }
        var obj = new Camera();
        obj.instance = instance;
        return obj;
    }

    public var cullMask(get, set): Int;
    public function get_cullMask(): Int {
        return cameraInstance.cullMask;
    }
    public function set_cullMask(value: Int): Void {
        cameraInstance.cullMask = value;
    }

    public var current(get, set): Bool;
    public function get_current(): Bool {
        return cameraInstance.current;
    }
    public function set_current(value: Bool): Void {
        cameraInstance.current = value;
    }

    public var dopplerTracking(get, set): Int;
    public function get_dopplerTracking(): Int {
        return cameraInstance.dopplerTracking;
    }
    public function set_dopplerTracking(value: Int): Void {
        cameraInstance.dopplerTracking = value;
    }

    public var far(get, set): Float;
    public function get_far(): Float {
        return cameraInstance.far;
    }
    public function set_far(value: Float): Void {
        cameraInstance.far = value;
    }

    public var fov(get, set): Float;
    public function get_fov(): Float {
        return cameraInstance.fov;
    }
    public function set_fov(value: Float): Void {
        cameraInstance.fov = value;
    }

    public var frustumOffset(get, set): Vector2;
    public function get_frustumOffset(): Vector2 {
        return cameraInstance.frustumOffset;
    }
    public function set_frustumOffset(value: Vector2): Void {
        cameraInstance.frustumOffset = value;
    }

    public var hOffset(get, set): Float;
    public function get_hOffset(): Float {
        return cameraInstance.hOffset;
    }
    public function set_hOffset(value: Float): Void {
        cameraInstance.hOffset = value;
    }

    public var keepAspect(get, set): Float;
    public function get_keepAspect(): Float {
        return cameraInstance.keepAspect;
    }
    public function set_keepAspect(value: Float): Void {
        cameraInstance.keepAspect = value;
    }

    public var near(get, set): Float;
    public function get_near(): Float {
        return cameraInstance.near;
    }
    public function set_near(value: Float): Void {
        cameraInstance.near = value;
    }

    public var projection(get, set): Int;
    public function get_projection(): Int {
        return cameraInstance.projection;
    }
    public function set_projection(value: Int): Void {
        cameraInstance.projection = value;
    }

    public var size(get, set): Float;
    public function get_size(): Float {
        return cameraInstance.size;
    }
    public function set_size(value: Float): Void {
        cameraInstance.size = value;
    }

    public var vOffset(get, set): Float;
    public function get_vOffset(): Float {
        return cameraInstance.vOffset;
    }
    public function set_vOffset(value: Float): Void {
        cameraInstance.vOffset = value;
    }

    public function clearCurrent(): Void {
        cameraInstance.clearCurrent();
    }

    public function getCullMaskValue(index: Int): Bool {
        return cameraInstance.getCullMaskValue(index);
    }

    //public function getFrustum() : lua.Table<Int, Plane>;

    public function isPositionBehind(position: NativeVector3): Bool {
        return cameraInstance.isPositionBehind(position);
    }

    public function makeCurrent(): Void {
        cameraInstance.makeCurrent();
    }

    public function projectLocalRayNormal(screenPoint: NativeVector2): Vector3 {
        return cameraInstance.projectLocalRayNormal(screenPoint);
    }

    public function projectPosition(screenPoint: NativeVector2, zDepth: Float): Vector3 {
        return cameraInstance.projectPosition(screenPoint, zDepth);
    }

    public function projectRayNormal(screenPoint: NativeVector2): Vector3 {
        return cameraInstance.projectRayNormal(screenPoint);
    }

    public function projectRayOrigin(screenPoint: NativeVector2): Vector3 {
        return cameraInstance.projectRayOrigin(screenPoint);
    }

    public function setCullMaskValue(index: Int, value: Bool): Void {
        cameraInstance.setCullMaskValue(index, value);
    }

    public function setFrustum(size: Float, offset: NativeVector2, zNear: Float, zFar: Float): Void {
        cameraInstance.setFrustum(size, offset, zNear, zFar);
    }

    public function setOrthagonal(size: Float, zNear: Float, zFar: Float): Void {
        cameraInstance.setOrthagonal(size, zNear, zFar);
    }

    public function setPerspective(fov: Float, zNear: Float, zFar: Float): Void {
        cameraInstance.setPerspective(fov, zNear, zFar);
    }

    public function unprojectPosition(position: NativeVector3): Vector2 {
        return cameraInstance.unprojectPosition(position);
    }

    public static function getFromEntity(entity: Entity): Camera {
        return Camera.fromInstance(
            CameraNative.getFromEntity(
                entity.entityInstance
            )
        );
    }
}