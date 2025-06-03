package sunaba.ui;

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
    public var dragEnded: sunaba.core.Event;
    public var dragStarted: sunaba.core.Event;
    public var dragged: sunaba.core.Event;
    public function clanpSplitOffset(): Void;
    public function getDragAreaControl(): sunaba.ui.Control;
    @:native("cast")
    public static function toSplitContainer(obj: Dynamic): sunaba.ui.SplitContainer;
}