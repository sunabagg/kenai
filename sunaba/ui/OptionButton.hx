package sunaba.ui;

@:native("OptionButton")
extern class OptionButton extends Button {
    public var actionMode: Int;
    public var allowReselect: Bool;
    public var fitToLongestItem: Bool;
}