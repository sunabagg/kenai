package sunaba.core;

@:native("Component")
extern class Component extends BaseObject {
    public function onInit() : Void;

    public function onReady() : Void;

    public function onUpdate(dt : Float) : Void;

    public function onPhysicsUpdate(dt : Float) : Void;

    public function setScriptType(type : Class<Component>) : Void;

    public function setScriptInstance(instance : Component) : Void;
}