package lucidfx.ui;

import lucidfx.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var aboutToPopup: lucidfx.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toMenuButton(obj: Dynamic): lucidfx.ui.MenuButton;
}

abstract MenuButtonAbstract(MenuButton) from MenuButton to MenuButton {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.MenuButton {
        var menuButton = lucidfx.ui.MenuButton.toMenuButton(element);
        if (menuButton.isNull()) {
            return null;
        }
        return menuButton;
    }
}