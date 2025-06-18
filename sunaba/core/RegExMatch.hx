package sunaba.core;

@:native("RegExMatch")
extern class RegExMatch extends BaseObject {
    public function new();
    public var names: Dictionary;
    public var strings: StringArray;
}