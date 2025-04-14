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
}