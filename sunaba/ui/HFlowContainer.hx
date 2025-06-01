package sunaba.ui;

@:native("HFlowContainer")
extern class HFlowContainer extends FlowContainer {
    @:native("cast")
    public static function toHFlowContainer(type: Dynamic): HFlowContainer;
}

abstract HFlowContainerAbstract(HFlowContainer) from HFlowContainer to HFlowContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): HFlowContainerAbstract {
        var hflow = HFlowContainer.toHFlowContainer(element);
        if (hflow.isNull()) {
            return null;
        }
        return hflow;
    }
}