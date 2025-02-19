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
}