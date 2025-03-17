package sunaba.spatial.mesh;

import sunaba.core.Vector3;
import sunaba.core.Component;
import sunaba.native.spatial.mesh.BoxNative;
import sunaba.core.BaseObject;

class Box extends Component {
    public var boxInstance(get, default) : BoxNative;
    public function get_boxInstance() : BoxNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new BoxNative();
        if (instance == null) {
            throw "Box.new() returned null";
        }

        boxInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance : BoxNative) : Box {
        if (instance == null) {
            throw "Box.fromInstance() received null instance";
        }
        var obj = new Box();
        obj.instance = instance;
        return obj;
    }

    public var size(get, set) : Vector3;
    public function get_size() : Vector3 {
        return boxInstance.size;
    }
    public function set_size(value : Vector3) : Vector3 {
        boxInstance.size = value;
        return value;
    }

    public var subdivideDepth(get, set) : Int;
    public function get_subdivideDepth() : Int {
        return boxInstance.subdivideDepth;
    }
    public function set_subdivideDepth(value : Int) : Int {
        boxInstance.subdivideDepth = value;
        return value;
    }

    public var subdivideWidth(get, set) : Int;
    public function get_subdivideWidth() : Int {
        return boxInstance.subdivideWidth;
    }
    public function set_subdivideWidth(value : Int) : Int {
        boxInstance.subdivideWidth = value;
        return value;
    }

    public var subdivideHeight(get, set) : Int;
    public function get_subdivideHeight() : Int {
        return boxInstance.subdivideHeight;
    }
    public function set_subdivideHeight(value : Int) : Int {
        boxInstance.subdivideHeight = value;
        return value;
    }
}

abstract BoxAbstract(Box) from Box to Box {
    @:from
    public static function fromBaseObject(obj: BaseObject) : BoxAbstract {
        return Box.fromInstance(cast obj.instance);
    }
    @:from
    public static function fromComponent(comp: Component) : BoxAbstract {
        return Box.fromInstance(cast comp.instance);
    }
}