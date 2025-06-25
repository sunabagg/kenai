package lucidfx.ui;

import lucidfx.core.Event;

@:native("ScrollBar")
extern class ScrollBar extends Range {
    public var customStep: Float;
    public var scrolling: Event;
    @:native("cast")
    public static function toScrollBar(obj: Dynamic): lucidfx.ui.ScrollBar;
}

abstract ScrollBarAbstract(ScrollBar) from ScrollBar to ScrollBar {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.ScrollBar {
        var scrollBar = lucidfx.ui.ScrollBar.toScrollBar(element);
        if (scrollBar.isNull()) {
            return null;
        }
        return scrollBar;
    }
}