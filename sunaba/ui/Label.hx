package sunaba.ui;

@:native("Label")
extern class Label extends Control {
    public var autowrapMode: Int;
    public var clipText: Bool;
    public var ellipsisChar: String;
}