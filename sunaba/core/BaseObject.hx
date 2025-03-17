package sunaba.core;

import sunaba.native.core.BaseObjectNative;

class BaseObject {
    public var instance: BaseObjectNative;

    public function new() {
        instance = new BaseObjectNative();
        if (instance == null) {
            throw "BaseObject.new() returned null";
        }
        pushToStack();
    }

    public function pushToStack() {
        var stack = GlobalObjectStack.getSingleton().stack;
        stack.push(new StackHandle(this));
    }

    public static function fromInstance(instance : BaseObjectNative) : BaseObject {
        if (instance == null) {
            throw "BaseObject.fromInstance() received null instance";
        }
        var obj = new BaseObject();
        obj.instance = instance;
        return obj;
    }

    function onFree() : Void {}


    function free() : Void {
        instance.free();
    }
}

abstract BaseObjectAbstract(BaseObject) from BaseObject to BaseObject {
    @:from
    public static function fromBaseObject(obj : BaseObject) : BaseObjectAbstract {
        return cast obj;
    }

    @:from
    public static function fromInstance(instance: BaseObjectNative) : BaseObjectAbstract {
        return BaseObject.fromInstance(instance);
    }
}