package sunaba.ui;

@:native("MarginContainer")
extern class MarginContainer extends Container {
    @:native("cast")
    public static function toMarginContainer(obj: Dynamic): sunaba.ui.MarginContainer;
}

abstract MarginContainerAbstract(MarginContainer) from MarginContainer to MarginContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.MarginContainer {
        var marginContainer = sunaba.ui.MarginContainer.toMarginContainer(element);
        if (marginContainer.isNull()) {
            return null;
        }
        return marginContainer;
    }
}