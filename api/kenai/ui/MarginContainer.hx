package kenai.ui;

@:native("MarginContainer")
extern class MarginContainer extends Container {
    @:native("cast")
    public static function toMarginContainer(obj: Dynamic): kenai.ui.MarginContainer;
}

abstract MarginContainerAbstract(MarginContainer) from MarginContainer to MarginContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.MarginContainer {
        var marginContainer = kenai.ui.MarginContainer.toMarginContainer(element);
        if (marginContainer.isNull()) {
            return null;
        }
        return marginContainer;
    }
}