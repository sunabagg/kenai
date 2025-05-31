package sunaba.ui;

@:native("ItemList")
extern class ItemList extends Control {
    public var allowReselect: Bool;
    public var allowRmbSelect: Bool;
    public var allowSearch: Bool;
    public var autoHeight: Bool;
    public var autoWidth: Bool;
    public var clipContents: Bool;
}