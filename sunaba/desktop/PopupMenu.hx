package lucidware.desktop;

import lucidware.core.Event;
import lucidware.input.InputEvent;
import lucidware.input.Shortcut;
import lucidware.core.Texture2D;
import lucidware.core.Color;
import lucidware.core.Variant;

@:native("PopupMenu")
extern class PopupMenu extends Popup {
    public var allowSearch: Bool;
    public var hideOnCheckableItemSelection: Bool;
    public var hideOnItemSelection: Bool;
    public var hideOnStateItemSelection: Bool;
    public var itemCount: Int;
    public var preferNativeMenu: Bool;
    public var submenuPopupDelay: Float;
    public var systemMenuId: Int;
    public var idFocused: Event;
    public var idPressed: Event;
    public var menuChanged: Event;
    public function activateItemByEvent(event: InputEvent, ?forGlobalOnly: Bool) : Void;
    public function addCheckItem(label: String, ?id: Int, ?accel: Int): Void;
    public function addCheckShortcut(shortcut: Shortcut, ?id: Int, ?global: Bool): Void;
    public function addIconCheckItem(texture: Texture2D, label: String, ?id: Int, ?accel: Int): Void;
    public function addIconCheckShortcut(texture: Texture2D, shortcut: Shortcut, ?id: Int, ?global: Bool): Void;
    public function addIconItem(texture: Texture2D, label: String, ?id: Int, ?accel: Int): Void;
    public function addIconRadioCheckItem(texture: Texture2D, label: String, ?id: Int, ?accel: Int): Void;
    public function addIconRadioCheckShortcut(texture: Texture2D, shortcut: Shortcut, ?id: Int, ?global: Bool): Void;
    public function addIconShortcut(texture: Texture2D, shortcut: Shortcut, ?id: Int, ?global: Bool, ?allowEcho: Bool): Void;
    public function addItem(label: String, id: Int, ?accel: Int): Void;
    public function addMultistateItem(label: String, maxStates: Int, defaultState: Int, ?id: Int, ?accel: Int): Void;
    public function addRadioCheckItem(label: String, ?id: Int, ?accel: Int): Void;
    public function addRadioCheckShortcut(shortcut: Shortcut, ?id: Int, ?global: Bool): Void;
    public function addSeparator(?label: String, ?id: Int): Void;
    public function addShortcut(shortcut: Shortcut, ?id: Int, ?global: Bool, ?allowEcho: Bool): Void;
    public function addSubmenuItem(label: String, submenu: String, ?id: Int, ?accel: Int): Void;
    public function addSubmenuNodeItem(label: String, submenu: PopupMenu, ?id: Int, ?accel: Int): Void;
    public function clear(?freeSubmenus: Bool): Void;
    public function getFocusedItem(): Int;
    public function getItemAccelerator(index: Int): Int;
    public function getItemIcon(index: Int): Texture2D;
    public function getItemIconMaxWidth(index: Int): Int;
    public function getItemIconModulate(index: Int): Color;
    public function getItemId(index: Int): Int;
    public function getItemIndent(id: Int): Int;
    public function getItemLanguage(index: Int): String;
    public function getItemMetadata(index: Int): Variant;
    public function getItemMultistate(index: Int): Int;
    public function getItemMultistateMax(index: Int): Int;
    public function getItemShortcut(index: Int): Shortcut;
    public function getItemSubmenu(index: Int): String;
    public function getItemSubmenuNode(index: Int): PopupMenu;
    public function getItemText(index: Int): String;
    public function getItemTextDirection(index: Int): Int;
    public function getItemTooltip(index: Int): String;
    public function isItemCheckable(index: Int): Bool;
    public function isItemChecked(index: Int): Bool;
    public function isItemDisabled(index: Int): Bool;
    public function isItemRadioCheckable(index: Int): Bool;
    public function isItemSeparator(index: Int): Bool;
    public function isItemShortcutDisabled(index: Int): Bool;
    public function isSystemMenu(): Bool;
    public function removeItem(index: Int): Void;
    public function scrollToItem(index: Int): Void;
    public function setFocusedItem(index: Int): Void;
    public function setItemAccelerator(index: Int, accel: Int): Void;
    public function setItemAsCheckable(index: Int, checkable: Bool): Void;
    public function setItemAsRadioCheckable(index: Int, radioCheckable: Bool): Void;
    public function setItemAsSeparator(index: Int, separator: Bool): Void;
    public function setItemChecked(index: Int, checked: Bool): Void;
    public function setItemDisabled(index: Int, disabled: Bool): Void;
    public function setItemIcon(index: Int, texture: Texture2D): Void;
    public function setItemIconMaxWidth(index: Int, maxWidth: Int): Void;
    public function setItemIconModulate(index: Int, modulate: Color): Void;
    public function setItemId(index: Int, id: Int): Void;
    public function setItemIndent(index: Int, indent: Int): Void;
    public function setItemLanguage(index: Int, language: String): Void;
    public function setItemMetadata(index: Int, metadata: Variant): Void;
    public function setItemMultistate(index: Int, state: Int): Void;
    public function setItemMultistateMax(index: Int, maxStates: Int): Void;
    public function setItemShortcut(index: Int, shortcut: Shortcut, ?global: Bool): Void;
    public function setItemShortcutDisabled(index: Int, disabled: Bool): Void;
    public function setItemSubmenu(index: Int, submenu: String): Void;
    public function setItemSubmenuNode(index: Int, submenu: PopupMenu): Void;
    public function setItemText(index: Int, text: String): Void;
    public function setItemTextDirection(index: Int, direction: Int): Void;
    public function setItemTooltip(index: Int, tooltip: String): Void;
    public function toggleItemChecked(index: Int): Void;
    public function toggleItemMultistate(index: Int): Void;
    @:native("cast")
    public static function toPopupMenu(type: Dynamic): PopupMenu;
}

abstract PopupMenuAbstract(PopupMenu) from PopupMenu to PopupMenu {
    @:from
    public static function fromElement(element: Element): PopupMenuAbstract {
        var menu = PopupMenu.toPopupMenu(element);
        if (menu.isNull()) {
            return null;
        }
        return menu;
    }
}