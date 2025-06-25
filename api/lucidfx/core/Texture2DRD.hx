package lucidfx.core;

@:native("Texture2DRD")
extern class Texture2DRD extends Texture2D {
    @:native("cast")
    public static function castFrom(type: Dynamic) : Texture2DRD;
}

abstract Texture2DRDAbstract(Texture2DRD) from Texture2DRD to Texture2DRD {
    @:from
    public static function fromResource(resource: Resource) : Texture2DRDAbstract {
        var txt2drd = Texture2DRD.castFrom(resource);
        if (txt2drd.isNull()) {
            return null;
        }
        return txt2drd;
    } 
}