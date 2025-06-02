package sunaba.ui;

import sunaba.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var flat: Bool;
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var toggleMode: Bool;
    public var aboutToPopup: sunaba.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
}