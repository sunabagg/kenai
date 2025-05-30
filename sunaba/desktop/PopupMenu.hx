package sunaba.desktop;

import sunaba.core.Event;

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
}