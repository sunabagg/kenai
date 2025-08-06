package sunaba.core;

@:native("Component")
extern class Component extends BaseObject {
    public function new();

    public var entity : Entity;

    public var scene : Scene;

    public function setScriptType(type : Dynamic) : Void;

    public function setScriptInstance(instance : Dynamic) : Void;
    
    public function onInit() : Void;

    public function onReady() : Void;

    public function onUpdate(deltaTime : Float) : Void;

    public function onPhysicsUpdate(deltaTime : Float) : Void;

    public function getData(): Dictionary;

    public function setData(data : Dictionary) : Void;
}