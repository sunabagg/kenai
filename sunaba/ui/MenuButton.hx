package lucidware.ui;

import lucidware.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var aboutToPopup: lucidware.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toMenuButton(obj: Dynamic): lucidware.ui.MenuButton;
}

abstract MenuButtonAbstract(MenuButton) from MenuButton to MenuButton {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.MenuButton {
        var menuButton = lucidware.ui.MenuButton.toMenuButton(element);
        if (menuButton.isNull()) {
            return null;
        }
        return menuButton;
    }
}