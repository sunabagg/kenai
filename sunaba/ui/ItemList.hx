package sunaba.ui;

import sunaba.core.Vector2i;

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
}