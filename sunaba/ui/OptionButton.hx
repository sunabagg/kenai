package sunaba.ui;

@:native("OptionButton")
extern class OptionButton extends Button {
    public var actionMode: Int;
    public var allowReselect: Bool;
    public var fitToLongestItem: Bool;
    public var itemCount: Int;
    public var selected: Int;
    public var itemFocused: sunaba.core.Event;
    public var itemSelected: sunaba.core.Event;
}