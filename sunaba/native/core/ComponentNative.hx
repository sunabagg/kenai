package sunaba.native.core;

@:native("Component")
extern class ComponentNative extends BaseObjectNative {
    public function new();

    public var entity : EntityNative;

    public var scene : SceneNative;

    public function setScriptType(type : Dynamic) : Void;

    public function setScriptInstance(instance : Dynamic) : Void;
    
    public function onInit() : Void;

    public function onReady() : Void;

    public function onUpdate(deltaTime : Float) : Void;

    public function onPhysicsUpdate(delatTime : Float) : Void;
}