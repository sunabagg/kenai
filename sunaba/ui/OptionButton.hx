package sunaba.ui;

import sunaba.core.Texture2D;

@:native("OptionButton")
extern class OptionButton extends Button {
    public var actionMode: Int;
    public var allowReselect: Bool;
    public var fitToLongestItem: Bool;
    public var itemCount: Int;
    public var selected: Int;
    public var itemFocused: sunaba.core.Event;
    public var itemSelected: sunaba.core.Event;
    public function addIconItem(texture: Texture2D, label: String, ?id: Int): Void;
    public function addItem(label: String, ?id: Int): Void;
    public function addSeparator(?text: String): Void;
    public function clear(): Void;
    public function getItemIcon(idx: Int): Texture2D;
    public function getItemId(idx: Int): Int;
}