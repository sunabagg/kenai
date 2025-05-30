package sunaba.ui;

@:native("FlowContainer")
extern class FlowContainer extends Container {
    public var alignment: Int;
    public var lastWrapAlignment: Int;
    public var reverseFill: Bool;
    public var vertical: Bool;
    public function getLineCount(): Int;
    @:native("cast")
    public function toFlowContainer(type: Dynamic): FlowContainer;
}