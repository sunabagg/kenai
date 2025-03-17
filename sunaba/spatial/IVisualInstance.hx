package sunaba.spatial;

import sunaba.native.spatial.IVisualInstanceNative;
import sunaba.core.Component;

class IVisualInstance extends Component {
    public var ivsInstance(get, default) : IVisualInstanceNative;
    public function get_ivsInstance() : IVisualInstanceNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new IVisualInstanceNative();
        if (instance == null) {
            throw "IVisualInstance.new() returned null";
        }

        ivsInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance : IVisualInstanceNative) : IVisualInstance {
        if (instance == null) {
            throw "IVisualInstance.fromInstance() received null instance";
        }
        var obj = new IVisualInstance();
        obj.instance = instance;
        return obj;
    }

    public  var layerMask(get, set) : Int;
    public function get_layerMask() : Int {
        return ivsInstance.layerMask;
    }
    public function set_layerMask(value : Int) : Void {
        ivsInstance.layerMask = value;
    }

    public var sortingOffset(get, set) : Float;
    public function get_sortingOffset() : Float {
        return ivsInstance.sortingOffset;
    }
    public function set_sortingOffset(value : Float) : Void {
        ivsInstance.sortingOffset = value;
    }

    public var sortingUseAabbCenter(get, set) : Bool;
    public function get_sortingUseAabbCenter() : Bool {
        return ivsInstance.sortingUseAabbCenter;
    }
    public function set_sortingUseAabbCenter(value : Bool) : Void {
        ivsInstance.sortingUseAabbCenter = value;
    }

    public function getLayerMaskValue(layer : Int) : Bool {
        return ivsInstance.getLayerMaskValue(layer);
    }

    public function setLayerMaskValue(layer : Int, value : Bool) : Void {
        ivsInstance.setLayerMaskValue(layer, value);
    }
}

abstract IVisualInstanceAbstract(IVisualInstance) from IVisualInstance to IVisualInstance {
    @:from
    public static function fromIVisualInstance(ivs : IVisualInstance) : IVisualInstanceAbstract {
        return cast ivs;
    }

    @:from
    public static function fromInstance(instance : IVisualInstanceNative) : IVisualInstanceAbstract {
        return IVisualInstance.fromInstance(instance);
    }
}