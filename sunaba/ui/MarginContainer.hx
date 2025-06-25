package lucidfx.ui;

@:native("MarginContainer")
extern class MarginContainer extends Container {
    @:native("cast")
    public static function toMarginContainer(obj: Dynamic): lucidfx.ui.MarginContainer;
}

abstract MarginContainerAbstract(MarginContainer) from MarginContainer to MarginContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.MarginContainer {
        var marginContainer = lucidfx.ui.MarginContainer.toMarginContainer(element);
        if (marginContainer.isNull()) {
            return null;
        }
        return marginContainer;
    }
}