package kenai.core;

@:native("BaseObject")
extern class BaseObject {
    function onFree() : Void;
    function free() : Void;
}