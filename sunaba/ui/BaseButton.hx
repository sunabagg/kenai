package sunaba.ui;

import sunaba.input.Shortcut;

@:native("BaseButton")
extern class BaseButton extends Control {
    public var actionMode: Int;
    public var buttonGroup: ButtonGroup;
    public var buttonMask: Int;
    public var buttonPressed: Bool;
    public var disabled: Bool;
    public var focusMode: Int;
    public var keepPressedOutside: Bool;
    public var shortcut: Shortcut;
    public var shortcutFeedback: Bool;
    public var toggleMode: Bool;
    public var buttonDown: Event;
    public var buttonUp: Event;
    public var pressed: Event;
}