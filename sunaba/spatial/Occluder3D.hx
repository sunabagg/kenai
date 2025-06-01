package sunaba.spatial;

import sunaba.core.Resource;
import sunaba.core.Vector3;

@:native("Occluder3D")
extern class Occluder3D extends Resource {
    public function getIndices(): lua.Table<Int, Int>;
    public function getVertices(): lua.Table<Int, Vector3>;
    @:native("cast")
    public static function castFrom(res: Dynamic): Occluder3D;
}

abstract Occluder3DAbstract(Occluder3D) from Occluder3D to Occluder3D {
    @:from
    public static function fromResource(resource: Resource) : Occluder3DAbstract {
        var occluder3D = Occluder3D.castFrom(resource);
        if (occluder3D.isNull()) {
            return null;
        }
        return occluder3D;
    }
} // end package sunaba.spatial