package sunaba.ui;

@:native("CheckButton")
extern class CheckButton extends Button {
    @:native("cast")
    public static function toCheckButton(type: Dynamic): CheckButton;
}

abstract CheckButtonAbstract(CheckButton) from CheckButton to CheckButton {
    @:from
    public static function fromElement(element: Element): CheckButtonAbstract {
        var btn = CheckButton.toCheckButton(element);
        if (btn.isNull()) {
            return null;
        }
        return btn;
    }
}