package lucidware.ui;

@:native("HboxContainer")
extern class HboxContainer extends BoxContainer {
    @:native("cast")
    public static function toHBoxContainer(type: Dynamic): HboxContainer;
}

abstract HboxContainerAbstract(HboxContainer) from HboxContainer to HboxContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): HboxContainerAbstract {
        var hbox = HboxContainer.toHBoxContainer(element);
        if (hbox.isNull()) {
            return null;
        }
        return hbox;
    }
}