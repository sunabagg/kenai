package sunaba.core;

@:native("Texture2DRD")
extern class Texture2DRD extends Texture2D {
    public static function castFrom(type: Dynamic) : Texture2DRD;
}

abstract Texture2DRDAbstract(Texture2DRD) from Texture2DRD to Texture2DRD {
    @:from
    public static function fromResource(resource: Resource) : Texture2DRDAbstract {
        return Texture2DRD.castFrom(resource);
    } 
}