package lucidware.ui;

@:native("MarginContainer")
extern class MarginContainer extends Container {
    @:native("cast")
    public static function toMarginContainer(obj: Dynamic): lucidware.ui.MarginContainer;
}

abstract MarginContainerAbstract(MarginContainer) from MarginContainer to MarginContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.MarginContainer {
        var marginContainer = lucidware.ui.MarginContainer.toMarginContainer(element);
        if (marginContainer.isNull()) {
            return null;
        }
        return marginContainer;
    }
}