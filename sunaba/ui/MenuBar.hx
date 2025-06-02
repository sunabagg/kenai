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
    public function isMenuDisabled(index: Int): Bool;
    public function isMenuHidden(index: Int): Bool;
    public function isNativeMenu(index: Int): Bool;
    public function setDisableShortcuts(disable: Bool): Void;
    public function setMenuDisabled(index: Int, disabled: Bool): Void;
    public function setMenuHidden(index: Int, hidden: Bool): Void;
    public function setMenuTitle(index: Int, title: String): Void;
    public function setMenuTooltip(index: Int, tooltip: String): Void;
}