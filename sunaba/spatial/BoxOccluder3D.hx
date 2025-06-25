package lucidware.spatial;

@native("BoxOccluder3D")
extern class BoxOccluder3D extends Occluder3D {
    public var size: Vector3;
    @:native("cast")
    public static function castFrom(res: Dynamic): BoxOccluder3D;
}

abstract BoxOccluder3DAbstract(BoxOccluder3D) from BoxOccluder3D to BoxOccluder3D {
    @:from
    public static function fromResource(resource: Resource) : BoxOccluder3DAbstract {
        var boxOccluder3D = BoxOccluder3D.castFrom(resource);
        if (boxOccluder3D.isNull()) {
            return null;
        }
        return boxOccluder3D;
    }
} // end package lucidware.spatial