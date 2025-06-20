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
    public var scrollStopped: Event;
    public function getHScrollBar(): HscrollBar;
    public function getVScrollBar(): VscrollBar;
    @:native("cast")
    public static function toScrollContainer(obj: Dynamic): sunaba.ui.ScrollContainer;
}

abstract ScrollContainerAbstract(ScrollContainer) from ScrollContainer to ScrollContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.ScrollContainer {
        var scrollContainer = sunaba.ui.ScrollContainer.toScrollContainer(element);
        if (scrollContainer.isNull()) {
            return null;
        }
        return scrollContainer;
    }
}