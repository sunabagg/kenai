package sunaba.ui;

import sunaba.core.Vector2i;
import sunaba.core.Event;

@:native("ItemList")
extern class ItemList extends Control {
    public var allowReselect: Bool;
    public var allowRmbSelect: Bool;
    public var allowSearch: Bool;
    public var autoHeight: Bool;
    public var autoWidth: Bool;
    public var clipContents: Bool;
    public var fixedColumnWidth: Int;
    public var fixedIconSize: Vector2i;
    public var focusMode: Int;
    public var iconMode: Int;
    public var iconScale: Float;
    public var itemCount: Int;
    public var maxColumns: Int;
    public var maxTextLines: Int;
    public var sameColumnWidth: Bool;
    public var selectMode: Int;
    public var textOverrunBehavior: Int;
    public var wraparoundItems: Bool;
    public var emptyClicked: Event;
    public var itemActivated: Event;
    public var itemClicked: Event;
    public var itemSelected: Event;
    public var multiSelected: Event;
}