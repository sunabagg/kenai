package lucidfx.spatial;

@:native("CameraAttributesPhysical")
extern class CameraAttributesPhysical extends CameraAttributes {
    public var autoExposureMaxExposureValue: Float;
    public var autoExposureMinExposureValue: Float;
    public var exposureAperture: Float;
    public var exposureShutterSpeed: Float;
    public var frustumFar: Float;
    public var frustumFocalLength: Float;
    public var frustumFocusDistance: Float;
    public var frustumNear: Float;
    public function getFov(): Float;
    @:native("cast")
    public static function castFrom(res: Dynamic): CameraAttributesPhysical;
}

abstract CameraAttributesPhysicalAbstract(CameraAttributesPhysical) from CameraAttributesPhysical to CameraAttributesPhysical {
    @:from
    public static function fromResource(resource: Resource) : CameraAttributesPhysicalAbstract {
        var cameraAttributesPhysical = CameraAttributesPhysical.castFrom(resource);
        if (cameraAttributesPhysical.isNull()) {
            return null;
        }
        return cameraAttributesPhysical;
    }
} // end package lucidfx.spatial