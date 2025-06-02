package sunaba.ui;

@:native("SpinBox")
extern class SpinBox extends Range{
    public var alignment: Int;
    public var customArrowStep: Bool;
    public var editable: Bool;
    public var prefix: String;
}