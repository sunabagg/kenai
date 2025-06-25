package lucidfx.ui;

@:native("VsplitContainer")
extern class VsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): lucidfx.ui.VsplitContainer;
}

abstract VsplitContainerAbstract(VsplitContainer) from VsplitContainer to VsplitContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.VsplitContainer {
        var vsplitContainer = lucidfx.ui.VsplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}