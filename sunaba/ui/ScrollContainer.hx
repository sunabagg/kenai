package sunaba.ui;

import sunaba.core.Event;

@:native("ScrollContainer")
extern class ScrollContainer extends Container {
    public var clipContents: Bool;
    public var drawFocusBorder: Bool;
    public var followFocus: Bool;
    public var horizontalScrollMode: Int;
    public var scrollDeadzone: Int;
    public var scrollHorizontal: Int;
    public var scrollHorizontalCustomStep: Float;
    public var scrollVertical: Int;
    public var scrollVerticalCustomStep: Float;
    public var verticalScrollMode: Int;
    public var scrollStarted: Event;
}