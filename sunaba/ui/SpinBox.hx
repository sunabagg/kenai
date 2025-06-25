package lucidware.ui;

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
    public function getLineEdit(): lucidware.ui.LineEdit;
    @:native("cast")
    public static function toSpinBox(obj: Dynamic): lucidware.ui.SpinBox;
}

abstract SpinBoxAbstract(SpinBox) from SpinBox to SpinBox {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.SpinBox {
        var spinBox = lucidware.ui.SpinBox.toSpinBox(element);
        if (spinBox.isNull()) {
            return null;
        }
        return spinBox;
    }
}