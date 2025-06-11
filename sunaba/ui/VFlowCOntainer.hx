package sunaba.ui;

@:native("VFlowContainer")
extern class VFlowContainer extends FlowContainer {
    @:native("cast")
    public static function toVFlowContainer(obj: Dynamic): VFlowContainer;
}

abstract VFlowContainerAbstract(VFlowContainer) from VFlowContainer to VFlowContainer {
    @:from
    public static function fromElement(element: Element): VFlowContainerAbstract {
        var vFlow: VFlowContainer = VFlowContainer.toVFlowContainer(element);
        if (vFlow.isNull()) {
            return null;
        }
        return vFlow;
    }
}