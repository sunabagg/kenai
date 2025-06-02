package sunaba.ui;

import sunaba.core.Event;

@:native("ScrollBar")
extern class ScrollBar extends Range {
    public var customStep: Float;
    public var step: Float;
    public var scrolling: Event;
    @:native("cast")
    public static function toScrollBar(obj: Dynamic): sunaba.ui.ScrollBar;
}

abstract ScrollBarAbstract(ScrollBar) from ScrollBar to ScrollBar {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.ScrollBar {
        var scrollBar = sunaba.ui.ScrollBar.toScrollBar(element);
        if (scrollBar.isNull()) {
            return null;
        }
        return scrollBar;
    }
}