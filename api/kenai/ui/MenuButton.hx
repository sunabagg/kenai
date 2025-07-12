package kenai.ui;

import kenai.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var aboutToPopup: kenai.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toMenuButton(obj: Dynamic): kenai.ui.MenuButton;
}

abstract MenuButtonAbstract(MenuButton) from MenuButton to MenuButton {
    @:from
    public static function fromElement(element: kenai.core.Element): MenuButtonAbstract {
        var menuButton = kenai.ui.MenuButton.toMenuButton(element);
        if (menuButton.isNull()) {
            return null;
        }
        return menuButton;
    }
}