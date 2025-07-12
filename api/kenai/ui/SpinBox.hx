package kenai.ui;

@:native("SpinBox")
extern class SpinBox extends Range{
    public var alignment: Int;
    public var customArrowStep: Bool;
    public var editable: Bool;
    public var prefix: String;
    public var selectAllOnFocus: Bool;
    public var suffix: String;
    public var updateOnTextChanged: Bool;
    public function apply(): Void;
    public function getLineEdit(): kenai.ui.LineEdit;
    @:native("cast")
    public static function toSpinBox(obj: Dynamic): kenai.ui.SpinBox;
}

abstract SpinBoxAbstract(SpinBox) from SpinBox to SpinBox {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.SpinBox {
        var spinBox = kenai.ui.SpinBox.toSpinBox(element);
        if (spinBox.isNull()) {
            return null;
        }
        return spinBox;
    }
}