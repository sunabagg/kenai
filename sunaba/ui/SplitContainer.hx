package lucidware.ui;

@:native("SplitContainer")
extern class SplitContainer extends Container {
    public var collapsed: Bool;
    public var dragAreaHighlightInEditor: Bool;
    public var dragAreaMarginBegin: Int;
    public var dragAreaMarginEnd: Int;
    public var dragAreaOffset: Int;
    public var draggerVisibility: Int;
    public var draggingEnabled: Bool;
    public var splitOffset: Int;
    public var vertical: Bool;
    public var dragEnded: lucidware.core.Event;
    public var dragStarted: lucidware.core.Event;
    public var dragged: lucidware.core.Event;
    public function clanpSplitOffset(): Void;
    public function getDragAreaControl(): lucidware.ui.Control;
    @:native("cast")
    public static function toSplitContainer(obj: Dynamic): lucidware.ui.SplitContainer;
}

abstract SplitContainerAbstract(SplitContainer) from SplitContainer to SplitContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.SplitContainer {
        var splitContainer = lucidware.ui.SplitContainer.toSplitContainer(element);
        if (splitContainer.isNull()) {
            return null;
        }
        return splitContainer;
    }
}