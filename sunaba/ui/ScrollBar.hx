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