package lucidware.ui;

import lucidware.core.Element;

@:native("VflowContainer")
extern class VflowContainer extends FlowContainer {
    @:native("cast")
    public static function toVFlowContainer(obj: Dynamic): VflowContainer;
}

abstract VflowContainerAbstract(VflowContainer) from VflowContainer to VflowContainer {
    @:from
    public static function fromElement(element: Element): VflowContainerAbstract {
        var vFlow: VflowContainer = VflowContainer.toVFlowContainer(element);
        if (vFlow.isNull()) {
            return null;
        }
        return vFlow;
    }
}