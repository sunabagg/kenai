package sunaba.native.core;

@:native("Scene")
extern class SceneNative extends BaseObjectNative {
    function addEntity(entity:EntityNative) : Void;
    function hasEntity(entity:EntityNative) : Bool;
    function removeEntity(entity:EntityNative) : Void;
    function getEntityCount() : Int;
    function find(path : String) : EntityNative;
    function getEntity(index: Int) : EntityNative;
}