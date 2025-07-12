package kenai.ui;

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
    public var dragEnded: kenai.core.Event;
    public var dragStarted: kenai.core.Event;
    public var dragged: kenai.core.Event;
    public function clanpSplitOffset(): Void;
    public function getDragAreaControl(): kenai.ui.Control;
    @:native("cast")
    public static function toSplitContainer(obj: Dynamic): kenai.ui.SplitContainer;
}

abstract SplitContainerAbstract(SplitContainer) from SplitContainer to SplitContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.SplitContainer {
        var splitContainer = kenai.ui.SplitContainer.toSplitContainer(element);
        if (splitContainer.isNull()) {
            return null;
        }
        return splitContainer;
    }
}