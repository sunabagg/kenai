package sunaba.desktop;

import sunaba.core.Event;
import sunaba.input.InputEvent;
import sunaba.input.Shortcut;
import sunaba.core.Texture2D;

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
}