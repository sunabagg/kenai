package sunaba.ui;

@:native("VsplitContainer")
extern class VsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): sunaba.ui.VsplitContainer;
}

abstract VsplitContainerAbstract(VsplitContainer) from VsplitContainer to VsplitContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VsplitContainer {
        var vsplitContainer = sunaba.ui.VsplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}