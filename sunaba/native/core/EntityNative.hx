package sunaba.native.core;

import sunaba.core.Component;

@:native("Entity")
extern class EntityNative extends BaseObjectNative {
    public var name : String;

    public function new();

    public function addComponent(comp: ComponentNative, name : String) : Void;

    public function hasComponent(comp : Component) : Bool;

    public function hasComponentByName(name : String) : Bool;

    public function removeComponent(comp : ComponentNative) : Void;

    
    public function getUserComponent(type : Class<Component>) : Component;

    public function getComponent(type : Class<ComponentNative>) : Component;

    public function getComponentByName(name : String) : Component;

    public function getComponentsByType(type : Class<ComponentNative>) : Array<ComponentNative>;

    public function getUserComponentsByType(type : Class<Component>) : Array<Component>;

    public function addChild(child: EntityNative): Void;

    public function removeChild(child: EntityNative): Void;

    public function hasChild(child: EntityNative): Bool;

    public function find(path : String) : EntityNative;

    public function getChildCount() : Int;

    public function getChild(index: Int) : EntityNative;
}