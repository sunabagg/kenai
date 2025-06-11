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
    public var hideRoot: Bool;
    public var scrollHorizontalEnabled: Bool;
    public var scrollVerticalEnabled: Bool;
    public var selectMode: Int;
    public var buttonClicked: Event;
    public var cellSelected: Event;
    public var checkPropagatedToItem: Event;
    public var columnTitleClicked: Event;
    public var customItemClicked: Event;
    public var customPopupEdited: Event;
    public var emptyClicked: Event;
    public var itemActivated: Event;
    public var itemCollapsed: Event;
    public var itemEdited: Event;
    public var itemIconDoubleClicked: Event;
    public var itemMouseSelected: Event;
    public var itemSelected: Event;
    public var multiSelected: Event;
    public var nothingSelected: Event;
    public function clear(): Void;
    public function createItem(?parent: TreeItem, ?index: Int): TreeItem;
    public function deselectAll(): Void;
    public function editSelected(?forceEdit: Bool): Void;
    public function ensureCursorIsVisible(): Void;
}