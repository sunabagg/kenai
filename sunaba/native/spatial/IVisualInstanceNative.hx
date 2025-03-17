package sunaba.native.spatial;

import sunaba.native.core.ComponentNative;

@:native("IVisualInstance")
extern class IVisualInstanceNative extends ComponentNative {
    public var layerMask : Int;
    public var sortingOffset : Float;
    public var sortingUseAabbCenter : Bool;
    public function getLayerMaskValue(layer : Int) : Bool;
    public function setLayerMaskValue(layer : Int, value : Bool) : Void;
}