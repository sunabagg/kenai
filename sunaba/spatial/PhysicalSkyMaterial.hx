package lucidfx.spatial;

import lucidfx.core.Texture2D;
import lucidfx.core.Material;

@:native("PhysicalSkyMaterial")
extern class PhysicalSkyMaterial extends Material {
    public var energyMultiplier: Float;
    public var groundColor: Color;
    public var mieCoefficient: Float;
    public var mieColor: Color;
    public var mieEccentricity: Float;
    public var nightSky: Texture2D;
    public var rayleighCoefficient: Float;
    public var rayleighColor: Color;
    public var sunDiskScale: Float;
    public var turbidity: Float;
    public var useDebanding: Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic): PhysicalSkyMaterial;
}

abstract PhysicalSkyMaterialAbstract(PhysicalSkyMaterial) from PhysicalSkyMaterial to PhysicalSkyMaterial {
    @:from
    public static function fromResource(resource: Resource): PhysicalSkyMaterialAbstract {
        var physicalSkyMaterial = PhysicalSkyMaterial.castFrom(resource);
        if (physicalSkyMaterial.isNull()) {
            return null;
        }
        return physicalSkyMaterial;
    } 
} // end package lucidfx.spatial