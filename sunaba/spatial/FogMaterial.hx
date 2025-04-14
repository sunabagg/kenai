package sunaba.spatial;

import sunaba.core.Color;
import sunaba.core.Material;

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
} // end package sunaba.spatial