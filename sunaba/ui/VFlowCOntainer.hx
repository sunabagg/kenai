package sunaba.ui;

@:native("VFlowContainer")
extern class VFlowCOntainer extends FlowContainer {
    @:native("cast")
    public static function toVFlowContainer(obj: Dynamic): VFlowCOntainer;
}

abstract VFlowContainerAbstract(VFlowCOntainer) from VFlowCOntainer to VFlowCOntainer {
    @:from
    public static function fromElement(element: Element): VFlowContainerAbstract {
        var vFlow: VFlowCOntainer = VFlowCOntainer.toVFlowContainer(element);
        if (vFlow.isNull()) {
            return null;
        }
        return vFlow;
    }
}