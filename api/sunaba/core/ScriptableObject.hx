package sunaba.core;

abstract class ScriptableObject {
    public function getData() : Dictionary {
        return new Dictionary();
    }

    public function setData(data: Dictionary) : Void {}

    public function new() {}
}