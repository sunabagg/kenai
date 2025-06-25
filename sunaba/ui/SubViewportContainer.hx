package lucidfx.ui;

import lucidfx.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): lucidfx.ui.SubViewportContainer;
}

abstract SubViewportContainerAbstract(SubViewportContainer) from SubViewportContainer to SubViewportContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.SubViewportContainer {
        var subViewportContainer = lucidfx.ui.SubViewportContainer.toSubViewportContainer(element);
        if (subViewportContainer.isNull()) {
            return null;
        }
        return subViewportContainer;
    }
}