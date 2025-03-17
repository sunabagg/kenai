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

    public static function fromInstance(instance : ComponentNative) : Component {
        if (instance == null) {
            throw "Component.fromInstance() received null instance";
        }
        var obj = new Component();
        obj.instance = instance;
        return obj;
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

    @:native("onInit")
    public function init() : Void {
        onInit();
    }

    @:native("onReady")
    public function ready() : Void {
        onReady();
    }

    @:native("onUpdate")
    public function update(deltaTime : Float) : Void {
        onUpdate(deltaTime);
    }

    @:native("onPhysicsUpdate")
    public function physicsUpdate(delatTime : Float) : Void {
        onPhysicsUpdate(delatTime);
    }
    
    @:native("__onInit")
    public function onInit() : Void {}

    @:native("__onReady")
    public function onReady() : Void {}

    @:native("__onUpdate")
    public function onUpdate(deltaTime : Float) : Void {}

    @:native("__onPhysicsUpdate")
    public function onPhysicsUpdate(delatTime : Float) : Void {}

    public function getComponentNG(type : Any, entity : Entity = null) {
        if (entity == null) {
            entity = this.component.entity;
        }

        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = cast entity.getComponent(compType);
            if (component != null) {
                return cast component;
            }
        }
        
        var behaviorType : Class<Behavior> = cast type;
        if (behaviorType != null) {
            var behavior : Behavior = entity.getUserComponent(behaviorType);
            if (behavior != null) {
                return cast behavior;
            }
        }

        return null;
    }

    @:generic
    public function getComponent<T>(type : Class<T>, entity : Entity = null) : T {
        if (entity == null) {
            entity = this.component.entity;
            trace("Entity is null, using this.component.entity");
        }

        var behaviorType : Class<Behavior> = cast type;
        if (ObjectUtils.typeInheritsFrom(type, Behavior)) {
            //trace("Checking for Behavior: " + Type.getClassName(type));
            var behavior : Behavior = entity.getUserComponent(behaviorType);
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
        } else {
            var typeName = untyped __lua__("type.__name");
            ///trace("Checking for Component: " + typeName);
            
            var component = entity.getComponentByName(typeName);
            if (component != null) {
                //trace("Component found: " + typeName);
                var tComponent : T = ObjectUtils.castObjectAs(type, component);
                if (tComponent != null) {
                    //trace("Component type match: " + typeName);
                    return tComponent;
                }
                else {
                    //trace("Component type mismatch: " + typeName);
                }
            }
            else {
                //trace("Component not found: " + typeName);
            }
        }
        
        

        //trace("Component or Behavior not found: " + Type.getClassName(type));

        return null;
    }
    
    public function addComponentNG(type : Any, entity : Entity = null) {
        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = Type.createInstance(compType, []);
            this.component.entity.addComponent(component, Type.getClassName(compType));
            return cast component;
        }

        var behaviorType : Class<Behavior> = cast type;
        if (behaviorType != null) {
            var behavior = Type.createInstance(behaviorType, []);
            var behaviorComp : Component = cast untyped behavior.component;
            if (behaviorComp != null) {
                this.component.entity.addComponent(behaviorComp, Type.getClassName(behaviorType));
                return cast behavior;
            }
        }
        
        throw "Invalid Component";
        return null;
    } 

    @:generic
    public function addComponent<T>(type : Class<T>, entity : Entity = null) : T {
        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = Type.createInstance(compType, []);
            this.component.entity.addComponent(component, Type.getClassName(compType));
            return cast component;
        }

        var behaviorType : Class<Behavior> = cast type;
        if (behaviorType != null) {
            var behavior = Type.createInstance(behaviorType, []);
            var behaviorComp : Component = cast untyped behavior.component;
            if (behaviorComp != null) {
                this.component.entity.addComponent(behaviorComp, Type.getClassName(behaviorType));
                return cast behavior;
            }
        }
        
        throw "Invalid Component";
        return null;
    } 

    public function removeComponent(type : Class<Any>, entity : Entity = null) : Void {
        if (entity == null) {
            entity = this.component.entity;
        }

        var compType : Class<Component> = cast type;
        if (compType != null) {
            var component : Component = cast entity.getComponent(compType);
            if (component != null) {
                entity.removeComponent(component);
            }
        }

        var behaviorType : Class<Behavior> = cast type;
        if (behaviorType != null) {
            var behavior : Behavior = cast entity.getUserComponent(behaviorType);
            if (behavior != null) {
                entity.removeUserComponent(behavior);
            }
        }
    }
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