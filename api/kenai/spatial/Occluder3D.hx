package kenai.spatial;

import kenai.core.Resource;
import kenai.core.Vector3;

@:native("Occluder3D")
extern class Occluder3D extends Resource {
    public function getIndices(): kenai.core.Vector<Int>;
    public function getVertices(): kenai.core.Vector<Vector3>;
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
} // end package kenai.spatial