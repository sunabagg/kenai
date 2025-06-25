package lucidware.spatial;

@:native("Texture3DRD")
extern class Texture3DRD extends Texture3D {
    @:native("cast")
    public static function castFrom(type: Dynamic): Texture3DRD;
}

abstract Texture3DRDAbstract(Texture3DRD) from Texture3DRD to Texture3DRD {
    @:from
    public static function fromResource(resource: Resource): Texture3DRDAbstract {
        var texture3d = Texture3DRD.castFrom(resource);
        if (texture3d.isNull()) {
            return null;
        }
        return texture3d;
    } 
} // end package lucidware.spatial