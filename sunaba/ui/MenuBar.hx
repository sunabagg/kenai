package sunaba.ui;

@:native("MenuBar")
extern class MenuBar extends Control {
    public var flat: Bool;
    public var language: String;
    public var preferGlobalMenu: Bool;
    public var startIndex: Int;
    public var switchOnHover: Bool;
    public var textDirection: Int;
}