package lucidware.ui;

import lucidware.core.Vector2;

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
    public function getButtonIdAtPosition(position: Vector2): Int;
    public function getColumnAtPosition(position: Vector2): Int;
    public function getColumnExpandRatio(column: Int): Int;
    public function getColumnTitle(column: Int): String;
    public function getColumnTitleAlignment(column: Int): Int;
    public function getColumnTitleDirection(column: Int): Int;
    public function getColumnTitleLanguage(column: Int): String;
    public function getColumnWidth(column: Int): Int;
    public function getCustomPopupRect(column: Int): Rect2;
    public function getDropSelectionAtPosition(position: Vector2): Int;
    public function getEdited(): TreeItem;
    public function getEditedColumn(): Int;
    public function getItemAreaRect(item: TreeItem, ?column: Int, ?buttonIndex: Int): Rect2;
    public function getItemAtPosition(position: Vector2): TreeItem;
    public function getNextSelected(from: TreeItem): TreeItem;
    public function getPressedButton(): TreeItem;
    public function getRoot(): TreeItem;
    public function getScroll(): Vector2;
    public function getSelected(): TreeItem;
    public function getSelectedColumn(): Int;
    public function isColumnClippingContent(column: Int): Bool;
    public function isColumnExpanding(column: Int): Bool;
    public function scrollToItem(item: TreeItem, ?centerOnItem: Bool): Void;
    public function setColumnCustomMinimumWidth(column: Int, minWidth: Int): Void;
    public function setColumnExpand(column: Int, expand: Bool): Void;
    public function setColumnExpandRatio(column: Int, ratio: Int): Void;
    public function setColumnTitle(column: Int, title: String): Void;
    public function setColumnTitleAlignment(column: Int, alignment: Int): Void;
    public function setColumnTitleDirection(column: Int, direction: Int): Void;
    public function setColumnTitleLanguage(column: Int, language: String): Void;
    @:native("cast")
    public static function toTree(obj: Dynamic): Tree;
}

abstract TreeAbstract(Tree) from Tree to Tree {
    @:from
    public static function fromElement(element: Element): ControlAbstract {
        var tree: Tree = Tree.toTree(element);
        if (tree.isNull()) {
            return null;
        }
        return tree;
    }
}