package lucidfx.ui;

@:native("HflowContainer")
extern class HflowContainer extends FlowContainer {
    @:native("cast")
    public static function toHFlowContainer(type: Dynamic): HflowContainer;
}

abstract HflowContainerAbstract(HflowContainer) from HflowContainer to HflowContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): HflowContainerAbstract {
        var hflow = HflowContainer.toHFlowContainer(element);
        if (hflow.isNull()) {
            return null;
        }
        return hflow;
    }
}