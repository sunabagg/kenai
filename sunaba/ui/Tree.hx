package sunaba.ui;

@:native("Tree")
extern class Tree extends Control {
    public var allowReselect: Bool;
    public var allowRmbSelect: Bool;
    public var allowSearch: Bool;
    public var autoTooltip: Bool;
    public var clipContents: Bool;
    public var columnTitlesVisible: Bool;
    public var columns: Int;
    public var dropModeFlags: Int;
    public var enableRecursiveFolding: Bool;
    public var focusMode: Bool;
    public var hideFolding: Bool;
}