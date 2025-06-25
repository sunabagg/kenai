package sunaba.spatial;

import sunaba.core.Resource;
import sunaba.core.Vector3;

@:native("Curve3D")
extern class Curve3D extends Resource {
    public var bakeInterval: Float;
    public var closed: Bool;
    public var pointCount: Int;
    public var upVectorEnabled: Bool;
    public function addPoint(pos: Vector3, _in: Vector3 = Vector3.zero(), out: Vector3 = Vector3.zero(), index: Int = 1): Void;
    public function clearPoints(): Void;
    public function getBakedLength(): Float;
    public function getBakedPoints(): lua.Table<Int, Vector3>;
    public function getBakedTilts(): lua.Table<Int, Float>;
    public function getBakedUpVectors(): lua.Table<Int, Vector3>;
    public function getClosestOffset(point: Vector3): Float;
    public function getClosestPoint(point: Vector3): Vector3;
    public function getPointIn(index: Int): Vector3;
    public function getPointOut(index: Int): Vector3;
    public function getPointPosition(index: Int): Vector3;
    public function getPointTilt(index: Int): Float;
    public function removePoint(index: Int): Void;
    public function sample(index: Int, t: Float): Vector3;
    public function sampleBaked(offset: Float = 0.0, cubic: Bool = false): Vector3;
    public function sampleBakedUpVector(offset: Float, applyTilt: Bool = false): Vector3;
    public function sampleBakedWithRotation(offset: Float = 0.0, cubic: Bool = false): Vector3;
    public function samplef(fofs: Float): Vector3;
    public function setPointIn(index: Int, _in: Vector3): Void;
    public function setPointOut(index: Int, out: Vector3): Void;
    public function setPointPosition(index: Int, pos: Vector3): Void;
    public function setPointTilt(index: Int, tilt: Float): Void;
    public function tessellate(maxStages: Int = 5, toleranceDegrees: Float = 4.0): lua.Table<Int, Vector3>;
    public function tessellateEvenLength(maxStages: Int = 5, toleranceLength: Float = 0.2): lua.Table<Int, Vector3>;
    @:native("cast")
    public static function castFrom(type: Dynamic): Curve3D;
}

abstract Curve3DAbstract(Curve3D) from Curve3D to Curve3D {
    @:from
    public static function fromResource(resource: Resource): Curve3DAbstract {
        var curve3D = Curve3D.castFrom(resource);
        if (curve3D.isNull()) {
            return null;
        }
        return curve3D;
    } 
} // end package sunaba.spatial