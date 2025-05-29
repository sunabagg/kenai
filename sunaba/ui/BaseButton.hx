package sunaba.ui;

@:native("BaseButton")
extern class BaseButton extends Control {
    public var actionMode: Int;
    public var buttonGroup: ButtonGroup;
    public var buttonMask: Int;
    public var buttonPressed: Bool;
    public var disabled: Bool;
}