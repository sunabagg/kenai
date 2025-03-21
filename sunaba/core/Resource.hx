package sunaba.core;

extern class Resource extends BaseObject {
    public function duplicate() : Resource;
    public function emitChanged() : Void;
    public function isNull() : Bool;
}