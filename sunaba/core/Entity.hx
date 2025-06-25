package lucidware.core;

@:native("Entity")
extern class Entity extends BaseObject {
    public var name : String;

    public function new();

    public function addComponent(comp: Component, name : String) : Void;

    public function hasComponent(comp : Behavior) : Bool;

    public function hasComponentByName(name : String) : Bool;

    public function removeComponent(comp : Component) : Void;

    public function removeUserComponent(comp : Behavior) : Void;
    
    public function getUserComponent(type : Class<Behavior>) : Behavior;

    public function getComponent(type : Class<Component>) : Component;

    public function getComponentByName(name : String) : Component;

    public function getComponentsByType(type : Class<Component>) : lua.Table<Int, Component>;

    public function getUserComponentsByType(type : Class<Behavior>) : lua.Table<Int, Behavior>;

    public function addChild(child: Entity): Void;

    public function removeChild(child: Entity): Void;

    public function hasChild(child: Entity): Bool;

    public function find(path : String) : Entity;

    public function getChildCount() : Int;

    public function getChild(index: Int) : Entity;
}