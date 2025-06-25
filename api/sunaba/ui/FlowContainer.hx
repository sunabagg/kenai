package sunaba.ui;

@:native("FlowContainer")
extern class FlowContainer extends Container {
    public var alignment: Int;
    public var lastWrapAlignment: Int;
    public var reverseFill: Bool;
    public var vertical: Bool;
    public function getLineCount(): Int;
    @:native("cast")
    public static function toFlowContainer(type: Dynamic): FlowContainer;
}

abstract FlowContainerAbstract(FlowContainer) from FlowContainer to FlowContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): FlowContainerAbstract {
        var container = FlowContainer.toFlowContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}