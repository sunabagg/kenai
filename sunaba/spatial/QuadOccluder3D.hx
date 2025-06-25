package lucidware.spatial;

import lucidware.core.Vector2;

@:native("QuadOccluder3D")
extern class QuadOccluder3D extends Occluder3D {
    public var size: Vector2;
    @:native("cast")
    public static function castFrom(type: Dynamic): QuadOccluder3D;
}

abstract QuadOccluder3DAbstract(QuadOccluder3D) from QuadOccluder3D to QuadOccluder3D {
    @:from
    public static function fromResource(resource: Resource) : QuadOccluder3DAbstract {
        var quadOccluder3D = QuadOccluder3D.castFrom(resource);
        if (quadOccluder3D.isNull()) {
            return null;
        }
        return quadOccluder3D;
    } 
} // end package lucidware.spatial