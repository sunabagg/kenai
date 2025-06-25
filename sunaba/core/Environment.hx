package lucidfx.core;

import lucidfx.spatial.Sky;

@:native("Environment")
extern class Environment extends Resource {
    public var adjustmentBrightness: Float;
    public var adjustmentColorCorrection: Float;
    public var adjustmentContrast: Float;
    public var adjustmentEnabled: Bool;
    public var adjustmentSaturation: Float;
    public var ambientLightColor: Color;
    public var ambientLightEnergy: Float;
    public var ambientLightSkyContribution: Float;
    public var ambientLightSource: Int;
    public var backgroundCameraFeedId: Int;
    public var backgroundCanvasMaxLayer: Int;
    public var backgroundColor: Color;
    public var backgroundEnergyMultiplier: Float;
    public var backgroundIntensity: Float;
    public var backgroundMode: Int;
    public var fogArialPerspective: Float;
    public var fogDensity: Float;
    public var fogDepthBegin: Float;
    public var fogDepthCurve: Float;
    public var fogDepthEnd: Float;
    public var fogEnabled: Bool;
    public var fogHeight: Float;
    public var fogHeightDensity: Float;
    public var fogLightColor: Color;
    public var fogLightEnergy: Float;
    public var fogMode: Int;
    public var fogSkyAffect: Bool;
    public var fogSunScatter: Float;
    public var glowBlendMode: Int;
    public var glowBloom: Float;
    public var glowEnabled: Bool;
    public var glowHdrLuminance: Float;
    public var glowHdrScale: Float;
    public var glowHdrThreshold: Float;
    public var glowIntensity: Float;
    public var glowLevel1: Float;
    public var glowLevel2: Float;
    public var glowLevel3: Float;
    public var glowLevel4: Float;
    public var glowLevel5: Float;
    public var glowLevel6: Float;
    public var glowLevel7: Float;
    public var glowMap: Texture;
    public var glowMapStrength: Bool;
    public var glowMix: Float;
    public var glowNormalized: Bool;
    public var glowStrength: Float;
    public var reflectedLightSource: Int;
    public var dynamicGiBounceFeedback: Float;
    public var dynamicGiCascade0Distance: Float;
    public var dynamicGiCascades: Int;
    public var dynamicGiEnabled: Bool;
    public var dynamicGiEnergy: Float;
    public var dyamicGiMaxDistance: Float;
    public var dyamicGiMinCellSize: Float;
    public var dynamicGiNormalBias: Float;
    public var dynamicGiProbeBias: Float;
    public var dynamicGiUseOcclusion: Bool;
    public var dynamicGiYScale: Float;
    public var sky: Sky;
    public var skyCustomFov: Float;
    public var skyRotation: Vector3;
    public var ssaoAoChannelAffect: Float;
    public var ssaoDetail: Float;
    public var ssaoEnabled: Bool;
    public var ssaoHorizon: Float;
    public var ssaoIntensity: Float;
    public var ssaoLightAffect: Float;
    public var ssaoPower: Float;
    public var ssaoRadius: Float;
    public var ssaoSharpness: Float;
    public var ssilEnabled: Bool;
    public var ssilIntensity: Float;
    public var ssilNormalRejection: Float;
    public var ssilRadius: Float;
    public var ssilSharpness: Float;
    public var ssrDepthTolerance: Float;
    public var ssrEnabled: Bool;
    public var ssrFadeIn: Float;
    public var ssrFadeOut: Float;
    public var ssrMaxSteps: Int;
    public var tonemapExposure: Float;
    public var tonemapMode: Int;
    public var tonemapWhite: Float;
    public var volumetricFogAlbedo: Color;
    public var volumetricFogAmbientInject: Float;
    public var volumetricFogAnisotropy: Float;
    public var volumetricFogDensity: Float;
    public var volumetricFogDetailSpread: Float;
    public var volumetricFogEmission: Color;
    public var volumetricFogEnabled: Bool;
    public var volumetricFogGiInject: Float;
    public var volumetricFogLength: Float;
    public var volumetricFogSkyAffect: Float;
    public var volumetricFogTemporalReprojectionAmount: Float;
    public var volumetricFogTemporalReprojectionEnabled: Bool;
    public function getGlowLevel(idx: Int): Float;
    public function setGlowLevel(idx: Int, level: Float): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic): Environment;
}

abstract EnvironmentAbstract(Environment) from Environment to Environment {
    @:from
    public static function fromResource(resource: Resource): EnvironmentAbstract {
        var environment = Environment.castFrom(resource);
        if (environment.isNull()) {
            return null;
        }
        return environment;
    } 
} // end package lucidfx.core