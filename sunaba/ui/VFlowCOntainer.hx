package sunaba.ui;

@:native("VFlowContainer")
extern class VFlowCOntainer extends FlowContainer {
    @:native("cast")
    public static function toVFlowContainer(obj: Dynamic): VFlowCOntainer;
}