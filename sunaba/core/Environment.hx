package sunaba.core;

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
}