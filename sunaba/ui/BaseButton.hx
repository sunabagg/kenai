package lucidware.ui;

import lucidware.core.Element;
import lucidware.input.Shortcut;
import lucidware.core.Resource;
import lucidware.core.Event;

@:native("BaseButton")
extern class BaseButton extends Control {
    public var actionMode: Int;
    public var buttonGroup: ButtonGroup;
    public var buttonMask: Int;
    public var buttonPressed: Bool;
    public var disabled: Bool;
    public var keepPressedOutside: Bool;
    public var shortcut: Shortcut;
    public var shortcutFeedback: Bool;
    public var toggleMode: Bool;
    public var buttonDown: Event;
    public var buttonUp: Event;
    public var pressed: Event;
    public var toggled: Event;
    public function getDrawMode(): Int;
    public function isHovered(): Bool;
    public function setPressedNoEvent(pressed: Bool): Void;
    @:native("cast")
    public static function toBaseButton(type: Dynamic): BaseButton;
}

abstract BaseButtonAbstract(BaseButton) from BaseButton to BaseButton {
    @:from
    public static function fromElement(element: Element): BaseButtonAbstract {
        var btn = BaseButton.toBaseButton(element);
        if (btn.isNull()) {
            return null;
        }
        return btn;
    }
}

