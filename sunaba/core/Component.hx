package sunaba.core;

import sunaba.native.core.ComponentNative;

class Component extends BaseObject {
    public var compInstance(get, default) : ComponentNative;
    public function get_compInstance() : ComponentNative {
        return cast instance;
    }
    public function new() {
        super();
        instance.free();
        instance = new ComponentNative();
        if (instance == null) {
            throw "Component.new() returned null";
        }
        var type = Type.getClass(this);
        if (type == null) {
            throw "Behavior must be a class";
        }
        compInstance.setScriptType(type);

        compInstance.setScriptInstance(this);
        pushToStack();
        
    }

    public static function fromInstance(instance : ComponentNative) : Component {
        if (instance == null) {
            throw "Component.fromInstance() received null instance";
        }
        var obj = new Component();
        obj.instance = instance;
        return obj;
    }
    
    public var entity(get, default) : Entity;
    public function get_entity() : Entity {
        return Entity.fromInstance(compInstance.entity);
    }
    /*
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

    public function getComponentNG(type : Any, entity : Entity = null) {
        if (entity == null) {
            entity = this.entity;
        }

        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = cast entity.getComponent(compType);
            if (component != null) {
                return cast component;
            }
        }

        return null;
    }

    @:generic
    public function getComponent<T>(type : Class<T>, entity : Entity = null) : T {
        if (entity == null) {
            entity = this.entity;
            trace("Entity is null, using this.component.entity");
        }

        var behaviorType : Class<Component> = cast type;
        if (ObjectUtils.typeInheritsFrom(type, Component)) {
            //trace("Checking for Behavior: " + Type.getClassName(type));
            var behavior : Component = entity.getComponent(behaviorType);
            if (behavior != null) {
                //trace("Behavior found: " + Type.getClassName(type));
                var tBehavior : T = cast behavior;
                if (tBehavior != null) {
                    //trace("Behavior type match: " + Type.getClassName(type));
                    return tBehavior;
                }
                else {
                    //trace("Behavior type mismatch: " + Type.getClassName(type));
                }
            }
            else {
                //trace("Behavior not found: " + Type.getClassName(type));
            }
        } 
        

        //trace("Component or Behavior not found: " + Type.getClassName(type));

        return null;
    }
    
    public function addComponentNG(type : Any, entity : Entity = null) {
        if (entity == null) {
            entity = this.entity;
        }

        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = Type.createInstance(compType, []);
            entity.addComponent(component, Type.getClassName(compType));
            return cast component;
        }
        
        throw "Invalid Component";
        return null;
    } 

    @:generic
    public function addComponent<T>(type : Class<T>, entity : Entity = null) : T {
        if (entity == null) {
            entity = this.entity;
        }
        
        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = Type.createInstance(compType, []);
            entity.addComponent(component, Type.getClassName(compType));
            return cast component;
        }
        
        throw "Invalid Component";
        return null;
    } 

    public function removeComponent(type : Class<Any>, entity : Entity = null) : Void {
        if (entity == null) {
            entity = this.entity;
        }

        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = cast entity.getComponent(compType);
            if (component != null) {
                entity.removeComponent(component);
            }
        }
    }
}

abstract ComponentAbstract(Component) from Component to Component {
    @:from
    public static function fromBaseObject(obj : BaseObject) : ComponentAbstract {
        return cast obj;
    }

    @:from
    public static function fromInstance(instance : ComponentNative) : ComponentAbstract {
        return Component.fromInstance(instance);
    }
    
}