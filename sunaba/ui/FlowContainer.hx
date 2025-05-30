package sunaba.ui;

@:native("FlowContainer")
extern class FlowContainer extends Container {
    public var alignment: Int;
    public var lastWrapAlignment: Int;
    public var reverseFill: Bool;
}