package sunaba.ui;

@:native("VSplitContainer")
extern class VSplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): sunaba.ui.VSplitContainer;
}

abstract VSplitContainerAbstract(VSplitContainer) from VSplitContainer to VSplitContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VSplitContainer {
        var vsplitContainer = sunaba.ui.VSplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}