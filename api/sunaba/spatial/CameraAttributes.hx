package sunaba.spatial;

import sunaba.core.Resource;

@:native("CameraAttributes")
extern class CameraAttributes extends Resource {
    public var autoExposureEnabled: Bool;
    public var autoExposureScale: Float;
    public var autoExposureSpeed: Float;
    public var exposureMultiplier: Float;
    public var exposureSensitivity: Float;
    @:native("cast")
    public static function castFrom(res: Dynamic): CameraAttributes;
}

abstract CameraAttributesAbstract(CameraAttributes) from CameraAttributes to CameraAttributes {
    @:from
    public static function fromResource(resource: Resource) : CameraAttributesAbstract {
        var cameraAttributes = CameraAttributes.castFrom(resource);
        if (cameraAttributes.isNull()) {
            return null;
        }
        return cameraAttributes;
    }
} // end package sunaba.spatial