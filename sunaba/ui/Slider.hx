package sunaba.ui;

@:native("Slider")
extern class Slider extends Range {
    public var editable: Bool;
    public var scrollable: Bool;
    public var tickCount: Int;
}
