package lucidware.ui;

import lucidware.core.Event;

@:native("ScrollBar")
extern class ScrollBar extends Range {
    public var customStep: Float;
    public var scrolling: Event;
    @:native("cast")
    public static function toScrollBar(obj: Dynamic): lucidware.ui.ScrollBar;
}

abstract ScrollBarAbstract(ScrollBar) from ScrollBar to ScrollBar {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.ScrollBar {
        var scrollBar = lucidware.ui.ScrollBar.toScrollBar(element);
        if (scrollBar.isNull()) {
            return null;
        }
        return scrollBar;
    }
}