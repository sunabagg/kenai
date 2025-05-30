package sunaba.desktop;

@:native("PopupMenu")
extern class PopupMenu extends Popup {
    public var allowSearch: Bool;
    public var hideOnCheckableItemSelection: Bool;
    public var hideOnItemSelection: Bool;
    public var hideOnStateItemSelection: Bool;
    public var itemCount: Int;
    public var preferNativeMneu: Bool;
    public var submenuPopupDelay: Float;
}