package lucidware.spatial;

import lucidware.core.Color;
import lucidware.core.Material;

@:native("FogMaterial")
extern class FogMaterial extends Material {
    public var albedo: Color;
    public var density: Float;
    public var edgeFade: Float;
    public var emission: Color;
    public var heightFalloff: Float;
    @:native("cast")
    public static function castFrom(type: Dynamic): FogMaterial;
}

abstract FogMaterialAbstract(FogMaterial) from FogMaterial to FogMaterial {
    @:from
    public static function fromResource(resource: Resource): FogMaterialAbstract {
        var fogMaterial = FogMaterial.castFrom(resource);
        if (fogMaterial.isNull()) {
            return null;
        }
        return fogMaterial;
    } 
} // end package lucidware.spatial