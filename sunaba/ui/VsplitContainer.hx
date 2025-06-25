package lucidware.ui;

@:native("VsplitContainer")
extern class VsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): lucidware.ui.VsplitContainer;
}

abstract VsplitContainerAbstract(VsplitContainer) from VsplitContainer to VsplitContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.VsplitContainer {
        var vsplitContainer = lucidware.ui.VsplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}