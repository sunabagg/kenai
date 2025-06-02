package sunaba.ui;

import sunaba.core.Event;

@:native("Slider")
extern class Slider extends Range {
    public var editable: Bool;
    public var scrollable: Bool;
    public var tickCount: Int;
    public var ticksOnBorders: Bool;
    public var dragEnded: Event;
}
