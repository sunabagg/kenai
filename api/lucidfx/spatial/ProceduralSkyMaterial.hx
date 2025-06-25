package lucidfx.spatial;

import lucidfx.core.Texture2D;
import lucidfx.core.Material;
import lucidfx.core.Color;

@:native("ProceduralSkyMaterial")
extern class ProceduralSkyMaterial extends Material {
    public var energyMultiplier: Float;
    public var groundBottomColor: Color;
    public var groundCurve: Float;
    public var groundEnergyMultiplier: Float;
    public var groundHorizonColor: Color;
    public var skyCover: Texture2D;
    public var skyCurve: Float;
    public var skyEnergyMultiplier: Float;
    public var skyHorizonColor: Color;
    public var skyTopColor: Color;
    public var sunAngleMax: Float;
    public var sunCurve: Float;
    public var useDebanding: Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic): ProceduralSkyMaterial;
}

abstract ProceduralSkyMaterialAbstract(ProceduralSkyMaterial) from ProceduralSkyMaterial to ProceduralSkyMaterial {
    @:from
    public static function fromResource(resource: Resource): ProceduralSkyMaterialAbstract {
        var proceduralSkyMaterial = ProceduralSkyMaterial.castFrom(resource);
        if (proceduralSkyMaterial.isNull()) {
            return null;
        }
        return proceduralSkyMaterial;
    } 
} // end package lucidfx.spatial