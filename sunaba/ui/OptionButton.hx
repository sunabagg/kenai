package lucidware.ui;

import lucidware.core.Texture2D;
import lucidware.core.Variant;

@:native("OptionButton")
extern class OptionButton extends Button {
    public var allowReselect: Bool;
    public var fitToLongestItem: Bool;
    public var itemCount: Int;
    public var selected: Int;
    public var itemFocused: lucidware.core.Event;
    public var itemSelected: lucidware.core.Event;
    public function addIconItem(texture: Texture2D, label: String, ?id: Int): Void;
    public function addItem(label: String, ?id: Int): Void;
    public function addSeparator(?text: String): Void;
    public function clear(): Void;
    public function getItemIcon(idx: Int): Texture2D;
    public function getItemId(idx: Int): Int;
    public function getItemIndex(id: Int): Int;
    public function getItemMetadata(idx: Int): Variant;
    public function getItemText(idx: Int): String;
    public function getItemTooltip(idx: Int): String;
    public function getSelectedItem(?fromLast: Bool): Int;
    public function getSelectedId(): Int;
    public function getSelectedMetadata(): Variant;
    public function hasSelectableItems(): Bool;
    public function isItemDisabled(idx: Int): Bool;
    public function removeItem(idx: Int): Void;
    public function select(idx: Int): Void;
    public function setDisableShortcuts(disable: Bool): Void;
    public function setItemDisabled(idx: Int, disabled: Bool): Void;
    public function setItemIcon(idx: Int, texture: Texture2D): Void;
    public function setItemId(idx: Int, id: Int): Void;
    public function setItemMetadata(idx: Int, metadata: Variant): Void;
    public function setItemText(idx: Int, text: String): Void;
    public function setItemTooltip(idx: Int, tooltip: String): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toOptionButton(obj: Dynamic): lucidware.ui.OptionButton;
}

abstract OptionButtonAbstract(OptionButton) from OptionButton to OptionButton {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.OptionButton {
        var optionButton = lucidware.ui.OptionButton.toOptionButton(element);
        if (optionButton.isNull()) {
            return null;
        }
        return optionButton;
    }
}