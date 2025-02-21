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

    @:generic
    public function getComponent<T>(entity : Entity = null) : T {
        if (entity == null) {
            entity = component.entity;
        }
        try {
            var comp = entity.getComponent(component.getType());
            if (comp != null) {
                return cast comp;
            }
        }
        catch (e : Dynamic) {}
        try {
            var userComp = entity.getUserComponent(component.getType());
            if (userComp != null) {
                return cast userComp;
            }
            return null;
        }
        catch (e : Dynamic) {}

        throw "Component not found";
        return null;
    }
}