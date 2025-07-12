package kenai.ui;

@:native("HsplitContainer")
extern class HsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): kenai.ui.HsplitContainer;
}

abstract HsplitContainerAbstract(HsplitContainer) from HsplitContainer to HsplitContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.HsplitContainer {
        var hsplitContainer = kenai.ui.HsplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}