package lucidware.ui;

import lucidware.core.Element;

@:native("CheckBox")
extern class CheckBox extends Button {
    @:native("cast")
    public static function toCheckBox(type: Dynamic): CheckBox;
}

abstract CheckBoxAbstract(CheckBox) from CheckBox to CheckBox {
    @:from
    public static function fromElement(element: Element): CheckBoxAbstract {
        var btn = CheckBox.toCheckBox(element);
        if (btn.isNull()) {
            return null;
        }
        return btn;
    }
}