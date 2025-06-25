package sunaba.ui;

@:native("HsplitContainer")
extern class HsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): sunaba.ui.HsplitContainer;
}

abstract HsplitContainerAbstract(HsplitContainer) from HsplitContainer to HsplitContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HsplitContainer {
        var hsplitContainer = sunaba.ui.HsplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}