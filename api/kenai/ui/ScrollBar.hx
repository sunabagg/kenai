package kenai.ui;

import kenai.core.Event;

@:native("ScrollBar")
extern class ScrollBar extends Range {
    public var customStep: Float;
    public var scrolling: Event;
    @:native("cast")
    public static function toScrollBar(obj: Dynamic): kenai.ui.ScrollBar;
}

abstract ScrollBarAbstract(ScrollBar) from ScrollBar to ScrollBar {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.ScrollBar {
        var scrollBar = kenai.ui.ScrollBar.toScrollBar(element);
        if (scrollBar.isNull()) {
            return null;
        }
        return scrollBar;
    }
}