package sunaba.spatial;

import sunaba.core.BaseObject;
import sunaba.native.spatial.IGeometryInstanceNative;

class IGeometryInstance extends IVisualInstance {
    public var igiInstance(get, default) : IGeometryInstanceNative;
    public function get_igiInstance() : IGeometryInstanceNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new IGeometryInstanceNative();
        if (instance == null) {
            throw "IGeometryInstance.new() returned null";
        }

        igiInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance : IGeometryInstanceNative) : IGeometryInstance {
        if (instance == null) {
            throw "IGeometryInstance.fromInstance() received null instance";
        }
        var obj = new IGeometryInstance();
        obj.instance = instance;
        return obj;
    }

    public var castShadow(get, set) : Int;
    public function get_castShadow() : Int {
        return igiInstance.castShadow;
    }
    public function set_castShadow(value : Int) : Int {
        igiInstance.castShadow = value;
        return value;
    }

    public var giMode(get, set) : Int;
    public function get_giMode() : Int {
        return igiInstance.giMode;
    }
    public function set_giMode(value : Int) : Int {
        igiInstance.giMode = value;
        return value;
    }

    public var lightmapScale(get, set) : Int;
    public function get_lightmapScale() : Int {
        return igiInstance.lightmapScale;
    }
    public function set_lightmapScale(value : Int) : Int {
        igiInstance.lightmapScale = value;
        return value;
    }

    public var lodBias(get, set) : Float;
    public function get_lodBias() : Float {
        return igiInstance.lodBias;
    }
    public function set_lodBias(value : Float) : Float {
        igiInstance.lodBias = value;
        return value;
    }

    public var transparancy(get, set) : Float;
    public function get_transparancy() : Float {
        return igiInstance.transparancy;
    }
    public function set_transparancy(value : Float) : Float {
        igiInstance.transparancy = value;
        return value;
    }

    public var visibilityRangeBegin(get, set) : Float;
    public function get_visibilityRangeBegin() : Float {
        return igiInstance.visibilityRangeBegin;
    }
    public function set_visibilityRangeBegin(value : Float) : Float {
        igiInstance.visibilityRangeBegin = value;
        return value;
    }

    public var visibilityRangeEnd(get, set) : Float;
    public function get_visibilityRangeEnd() : Float {
        return igiInstance.visibilityRangeEnd;
    }
    public function set_visibilityRangeEnd(value : Float) : Float {
        igiInstance.visibilityRangeEnd = value;
        return value;
    }

    public var visibilityRangeBeginMargin(get, set) : Float;
    public function get_visibilityRangeBeginMargin() : Float {
        return igiInstance.visibilityRangeBeginMargin;
    }
    public function set_visibilityRangeBeginMargin(value : Float) : Float {
        igiInstance.visibilityRangeBeginMargin = value;
        return value;
    }

    public var visibilityRangeEndMargin(get, set) : Float;
    public function get_visibilityRangeEndMargin() : Float {
        return igiInstance.visibilityRangeEndMargin;
    }
    public function set_visibilityRangeEndMargin(value : Float) : Float {
        igiInstance.visibilityRangeEndMargin = value;
        return value;
    }

    public var visibilityRangeFadeMode(get, set) : Float;
    public function get_visibilityRangeFadeMode() : Float {
        return igiInstance.visibilityRangeFadeMode;
    }
    public function set_visibilityRangeFadeMode(value : Float) : Float {
        igiInstance.visibilityRangeFadeMode = value;
        return value;
    }
}

abstract IGeometryInstanceAbstract(IGeometryInstance) from IGeometryInstance to IGeometryInstance {
    @:from
    public static function fromBaseObject(obj : BaseObject) : IGeometryInstanceAbstract {
        return IGeometryInstance.fromInstance(cast obj.instance);
    }

    @:from
    public static function fromInstance(instance : IGeometryInstanceNative) : IGeometryInstanceAbstract {
        return IGeometryInstance.fromInstance(instance);
    }
}