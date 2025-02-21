package sunaba.core;

class Behavior {
    public var component : Component;
    
    public function new() {
        var type = Type.getClass(this);
        if (type == null) {
            throw "Behavior must be a class";
        }

        var comp = new Component();
        component = comp;
        comp.setScriptType(type);

        comp.setScriptInstance(this);
    }

    public function onInit() : Void {}

    public function onReady() : Void {}

    public function onUpdate(deltaTime : Float) : Void {}

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

        var compType : Class<Component> = cast type;
        var isComponent : Bool = cast untyped __lua__("type(type) == 'userdata'") == true;
        if (compType != null) {
            trace("Checking for Component: " + Type.getClassName(type));
            var component = entity.getComponentByName(Type.getClassName(type));
            if (component != null) {
                trace("Component found: " + Type.getClassName(type));
                var tComponent : T = cast component;
                if (tComponent != null) {
                    trace("Component type match: " + Type.getClassName(type));
                    return tComponent;
                }
                else {
                    trace("Component type mismatch: " + Type.getClassName(type));
                }
            }
            else {
                trace("Component not found: " + Type.getClassName(type));
            }
        }
        
        var behaviorType : Class<Behavior> = cast type;
        if (behaviorType != null) {
            trace("Checking for Behavior: " + Type.getClassName(type));
            var behavior : Behavior = entity.getUserComponent(behaviorType);
            if (behavior != null) {
                trace("Behavior found: " + Type.getClassName(type));
                var tBehavior : T = cast behavior;
                if (tBehavior != null) {
                    trace("Behavior type match: " + Type.getClassName(type));
                    return tBehavior;
                }
                else {
                    trace("Behavior type mismatch: " + Type.getClassName(type));
                }
            }
            else {
                trace("Behavior not found: " + Type.getClassName(type));
            }
        }

        trace("Component or Behavior not found: " + Type.getClassName(type));

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