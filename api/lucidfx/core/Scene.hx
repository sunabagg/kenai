package lucidfx.core;

@:native("Scene")
extern class Scene extends BaseObject {
    function addEntity(entity:Entity) : Void;
    function hasEntity(entity:Entity) : Bool;
    function removeEntity(entity:Entity) : Void;
    function getEntityCount() : Int;
    function find(path : String) : Entity;
    function getEntity(index: Int) : Entity;
}