package sunaba.ui;

@:native("HFlowContainer")
extern class HFlowContainer extends FlowContainer {
    @:native("cast")
    public function toHFlowContainer(type: Dynamic): HFlowContainer;
}