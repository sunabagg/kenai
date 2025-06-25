package lucidware.spatial;

@:native("CameraAttributes")
extern class CameraAttributesPractical extends CameraAttributes {
    public var autoExposureMaxSensitivity: Float;
    public var autoExposureMinSensitivity: Float;
    public var dofBlurAmount: Float;
    public var dofBlurFarDistance: Float;
    public var dofBlurFarEnabled: Bool;
    public var dofBlurFarTransition: Float;
    public var dofBlurNearDistance: Float;
    public var dofBlurNearEnabled: Bool;
    public var dofBlurNearTransition: Float;
    @:native("cast")
    public static function castFrom(res: Dynamic): CameraAttributesPractical;
}

abstract CameraAttributesPracticalAbstract(CameraAttributesPractical) from CameraAttributesPractical to CameraAttributesPractical {
    @:from
    public static function fromResource(resource: Resource) : CameraAttributesPracticalAbstract {
        var cameraAttributesPractical = CameraAttributesPractical.castFrom(resource);
        if (cameraAttributesPractical.isNull()) {
            return null;
        }
        return cameraAttributesPractical;
    }
} // end package lucidware.spatial