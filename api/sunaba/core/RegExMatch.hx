package sunaba.core;

@:native("RegExMatch")
extern class RegExMatch extends BaseObject {
    public function new();
    public var names: Dictionary;
    public var strings: StringArray;
    public var subject: String;
    public function getEnd(?name: Variant): Int;
    public function getGroupCount(): Int;
    public function getStart(?name: Variant): Int;
    public function getString(?name: Variant): String;
    public function isValid(): Bool;
    public function isNull(): Bool;
}