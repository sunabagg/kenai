package lucidware.spatial;

@:native("SphereOccluder3D")
extern class SphereOccluder3D extends Occluder3D {
    public var radius: Float;
    @:native("cast")
    public static function castFrom(type: Dynamic): SphereOccluder3D;
}

abstract SphereOccluder3DAbstract(SphereOccluder3D) from SphereOccluder3D to SphereOccluder3D {
    @:from
    public static function fromResource(resource: Resource): SphereOccluder3DAbstract {
        var sphereOccluder = SphereOccluder3D.castFrom(resource);
        if (sphereOccluder.isNull()) {
            return null;
        }
        return sphereOccluder;
    } 
} // end package lucidware.spatial