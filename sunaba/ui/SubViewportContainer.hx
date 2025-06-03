package sunaba.ui;

import sunaba.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): sunaba.ui.SubViewportContainer;
}

abstract SubViewportContainerAbstract(SubViewportContainer) from SubViewportContainer to SubViewportContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.SubViewportContainer {
        var subViewportContainer = sunaba.ui.SubViewportContainer.toSubViewportContainer(element);
        if (subViewportContainer.isNull()) {
            return null;
        }
        return subViewportContainer;
    }
}