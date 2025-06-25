package lucidware.ui;

import lucidware.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): lucidware.ui.SubViewportContainer;
}

abstract SubViewportContainerAbstract(SubViewportContainer) from SubViewportContainer to SubViewportContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.SubViewportContainer {
        var subViewportContainer = lucidware.ui.SubViewportContainer.toSubViewportContainer(element);
        if (subViewportContainer.isNull()) {
            return null;
        }
        return subViewportContainer;
    }
}