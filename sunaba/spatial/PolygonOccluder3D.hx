package lucidware.spatial;

import lucidware.core.Vector2;

@:native("PolygonOccluder3D")
extern class PolygonOccluder3D extends Occluder3D {
    public var polygon: lua.Table<Int, Vector2>;
    @:native("cast")
    public static function castFrom(type: Dynamic): PolygonOccluder3D;
}

abstract PolygonOccluder3DAbstract(PolygonOccluder3D) from PolygonOccluder3D to PolygonOccluder3D {
    @:from
    public static function fromResource(resource: Resource) : PolygonOccluder3DAbstract {
        var polygonOccluder3D = PolygonOccluder3D.castFrom(resource);
        if (polygonOccluder3D.isNull()) {
            return null;
        }
        return polygonOccluder3D;
    } 
} // end package lucidware.spatial