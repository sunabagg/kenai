package lucidfx.ui;

@:native("HsplitContainer")
extern class HsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): lucidfx.ui.HsplitContainer;
}

abstract HsplitContainerAbstract(HsplitContainer) from HsplitContainer to HsplitContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.HsplitContainer {
        var hsplitContainer = lucidfx.ui.HsplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}