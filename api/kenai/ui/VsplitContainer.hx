package kenai.ui;

@:native("VsplitContainer")
extern class VsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): kenai.ui.VsplitContainer;
}

abstract VsplitContainerAbstract(VsplitContainer) from VsplitContainer to VsplitContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.VsplitContainer {
        var vsplitContainer = kenai.ui.VsplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}