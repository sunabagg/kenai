package sunaba.spatial;

import sunaba.core.Material;
import sunaba.core.Texture2D;

@:native("PanoramaSkyMaterial")
extern class PanoramaSkyMaterial extends Material {
    public var energyMultiplier: Float;
    public var filterEnabled: Bool;
    public var panorama: Texture2D;
    @:native("cast")
    public static function castFrom(type: Dynamic): PanoramaSkyMaterial;
}

abstract PanoramaSkyMaterialAbstract(PanoramaSkyMaterial) from PanoramaSkyMaterial to PanoramaSkyMaterial {
    @:from
    public static function fromResource(resource: Resource): PanoramaSkyMaterialAbstract {
        var panoramaSkyMaterial = PanoramaSkyMaterial.castFrom(resource);
        if (panoramaSkyMaterial.isNull()) {
            return null;
        }
        return panoramaSkyMaterial;
    } 
} // end package sunaba.spatial