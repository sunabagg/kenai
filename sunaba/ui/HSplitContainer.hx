package sunaba.ui;

@:native("HSplitContainer")
extern class HSplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): sunaba.ui.HSplitContainer;
}

abstract HSplitContainerAbstract(HSplitContainer) from HSplitContainer to HSplitContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HSplitContainer {
        var hsplitContainer = sunaba.ui.HSplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}