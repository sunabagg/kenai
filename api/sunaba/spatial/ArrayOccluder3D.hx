package sunaba.spatial;

import sunaba.core.Vector3;

@:native("ArrayOccluder3D")
extern class ArrayOccluder3D extends Occluder3D {
    public var indices: lua.Vector<Int>;
    public var vertices: lua.Vector<Vector3>;
    public function setArrays(vertices: lua.Vector<Vector3>, indices: lua.Vector<Int>): Void;
    @:native("cast")
    public static function castFrom(res: Dynamic): ArrayOccluder3D;
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