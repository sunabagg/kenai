package sunaba.spatial;

import sunaba.core.Vector3;

@:native("ArrayOccluder3D")
extern class ArrayOccluder3D extends Occluder3D {
    public var indices: Array<Int>;
    public var vertices: Array<Vector3>;
    public function setArrays(vertices: Array<Vector3>, indices: Array<Int>): Void;
    @:native("cast")
    public function castFrom(res: Dynamic): ArrayOccluder3D;
}

abstract ArrayOccluder3DAbstract(ArrayOccluder3D) from ArrayOccluder3D to ArrayOccluder3D {
    @:from
    public static function fromResource(resource: Resource) : ArrayOccluder3DAbstract {
        var arrayOccluder3D = ArrayOccluder3D.castFrom(resource);
        if (arrayOccluder3D.isNull()) {
            return null;
        }
        return arrayOccluder3D;
    }
} // end package sunaba.spatial