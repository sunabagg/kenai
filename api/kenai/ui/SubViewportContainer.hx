package kenai.ui;

import kenai.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): kenai.ui.SubViewportContainer;
}

abstract SubViewportContainerAbstract(SubViewportContainer) from SubViewportContainer to SubViewportContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.SubViewportContainer {
        var subViewportContainer = kenai.ui.SubViewportContainer.toSubViewportContainer(element);
        if (subViewportContainer.isNull()) {
            return null;
        }
        return subViewportContainer;
    }
}