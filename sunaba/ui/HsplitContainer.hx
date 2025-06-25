package lucidware.ui;

@:native("HsplitContainer")
extern class HsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): lucidware.ui.HsplitContainer;
}

abstract HsplitContainerAbstract(HsplitContainer) from HsplitContainer to HsplitContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.HsplitContainer {
        var hsplitContainer = lucidware.ui.HsplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}