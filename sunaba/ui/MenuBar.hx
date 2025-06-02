package sunaba.ui;

import sunaba.desktop.PopupMenu;

@:native("MenuBar")
extern class MenuBar extends Control {
    public var flat: Bool;
    public var language: String;
    public var preferGlobalMenu: Bool;
    public var startIndex: Int;
    public var switchOnHover: Bool;
    public var textDirection: Int;
    public function getMenuCount(): Int;
    public function getMenuPopup(index: Int): PopupMenu;
    public function getMenuTitle(index: Int): String;
    public function getMenuTooltip(index: Int): String;
}