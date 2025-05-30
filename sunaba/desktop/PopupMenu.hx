package sunaba.desktop;

import sunaba.core.Event;
import sunaba.input.InputEvent;
import sunaba.input.Shortcut;

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
}