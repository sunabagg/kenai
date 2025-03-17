package sunaba.core;

import sunaba.native.core.ComponentNative;

class Component extends BaseObject {
    public var compInstance(get, default) : ComponentNative;
    public function get_compInstance() : ComponentNative {
        return cast instance;
    }
    public function new() {
        instance = new ComponentNative();
        if (instance == null) {
            throw "Component.new() returned null";
        }
        var type = Type.getClass(this);
        if (type == null) {
            throw "Behavior must be a class";
        }
        comp.setScriptType(type);

        comp.setScriptInstance(this);
        pushToStack();
        compInstance = instance;
    }
    /*
    public var entity(get, default) : Entity;
    public function get_entity() : Entity {
        return Entity.fromInstance(compInstance.entity);
    }

    public var scene(get, default) : Scene;
    public function get_scene() : Scene {
        return Scene.fromInstance(compInstance.scene);
    }*/

    public function init() : Void {
        onInit();
    }

    public function ready() : Void {
        onReady();
    }

    public function update(deltaTime : Float) : Void {
        onUpdate(deltaTime);
    }

    public function physicsUpdate(delatTime : Float) : Void {
        onPhysicsUpdate(delatTime);
    }
    
    public function onInit() : Void {}

    public function onReady() : Void {}

    public function onUpdate(deltaTime : Float) : Void {}

    public function onPhysicsUpdate(delatTime : Float) : Void {}
}

abstract ComponentAbstract(Component) from Component to Component {
    @:from
    public static function fromComponent(comp : Component) : ComponentAbstract {
        return cast comp;
    }

    @:from
    public static function fromInstance(instance : ComponentNative) : ComponentAbstract {
        return Component.fromInstance(instance);
    }
    
}