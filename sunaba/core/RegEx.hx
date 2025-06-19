package sunaba.core;

@:native("RegEx")
extern class RegEx extends BaseObject {
    public function new();
    public function compile(pattern: String, ?showError: Bool): Void;
    public function createFromString(pattern: String, ?showError: Bool): RegEx;
    public function getGroupCount(): Int;
}