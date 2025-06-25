package lucidfx.ui;

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
    public var dragEnded: lucidfx.core.Event;
    public var dragStarted: lucidfx.core.Event;
    public var dragged: lucidfx.core.Event;
    public function clanpSplitOffset(): Void;
    public function getDragAreaControl(): lucidfx.ui.Control;
    @:native("cast")
    public static function toSplitContainer(obj: Dynamic): lucidfx.ui.SplitContainer;
}

abstract SplitContainerAbstract(SplitContainer) from SplitContainer to SplitContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.SplitContainer {
        var splitContainer = lucidfx.ui.SplitContainer.toSplitContainer(element);
        if (splitContainer.isNull()) {
            return null;
        }
        return splitContainer;
    }
}