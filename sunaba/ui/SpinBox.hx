package sunaba.ui;

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
    public function getLineEdit(): sunaba.ui.LineEdit;
    @:native("cast")
    public static function toSpinBox(obj: Dynamic): sunaba.ui.SpinBox;
}

abstract SpinBoxAbstract(SpinBox) from SpinBox to SpinBox {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.SpinBox {
        var spinBox = sunaba.ui.SpinBox.toSpinBox(element);
        if (spinBox.isNull()) {
            return null;
        }
        return spinBox;
    }
}