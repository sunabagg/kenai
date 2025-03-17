package sunaba.native.core;

@:native("BaseObject")
extern class BaseObjectNative {
    public function new();
    function onFree() : Void;
    function free() : Void;
}