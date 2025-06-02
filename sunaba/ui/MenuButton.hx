package sunaba.ui;

import sunaba.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var flat: Bool;
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var aboutToPopup: sunaba.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toMenuButton(obj: Dynamic): sunaba.ui.MenuButton;
}

abstract MenuButtonAbstract(MenuButton) from MenuButton to MenuButton {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.MenuButton {
        var menuButton = sunaba.ui.MenuButton.toMenuButton(element);
        if (menuButton.isNull()) {
            return null;
        }
        return menuButton;
    }
}