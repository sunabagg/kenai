package sunaba.ui;

@:native("SplitContainer")
extern class SplitContainer extends Container {
    public var collapsed: Bool;
    public var dragAreaHighlightInEditor: Bool;
    public var dragAreaMarginBegin: Int;
    public var dragAreaMarginEnd: Int;
}