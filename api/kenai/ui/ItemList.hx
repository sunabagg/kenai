package kenai.ui;

import kenai.core.Vector2i;
import kenai.core.Event;
import kenai.core.Texture2D;
import kenai.core.Vector2;
import kenai.core.Color;
import kenai.core.Rect2;

@:native("ItemList")
extern class ItemList extends Control {
    public var allowReselect: Bool;
    public var allowRmbSelect: Bool;
    public var allowSearch: Bool;
    public var autoHeight: Bool;
    public var autoWidth: Bool;
    public var clipContents: Bool;
    public var fixedColumnWidth: Int;
    public var fixedIconSize: Vector2i;
    public var iconMode: Int;
    public var iconScale: Float;
    public var itemCount: Int;
    public var maxColumns: Int;
    public var maxTextLines: Int;
    public var sameColumnWidth: Bool;
    public var selectMode: Int;
    public var textOverrunBehavior: Int;
    public var wraparoundItems: Bool;
    public var emptyClicked: Event;
    public var itemActivated: Event;
    public var itemClicked: Event;
    public var itemSelected: Event;
    public var multiSelected: Event;
    public function addIconItem(texture: Texture2D, ?selectable: Bool): Void;
    public function addItem(test: String, ?icon: Texture2D, ?selectable: Bool): Void;
    public function clear(): Void;
    public function deselect(index: Int): Void;
    public function deselectAll(): Void;
    public function ensureCurrentIsVisible(): Void;
    public function forceUpdateListSize(): Void;
    public function getHScrollBar(): HscrollBar;
    public function getItemAtPosition(position: Vector2, ?exact: Bool): Int;
    public function getItemAutoTranslate(index: Int): Int;
    public function getItemCustomBgColor(index: Int): Color;
    public function getItemCustomFgColor(index: Int): Color;
    public function getItemIcon(index: Int): Texture2D;
    public function getItemIconModulate(index: Int): Color;
    public function getItemIconRegion(index: Int): Rect2;
    public function getItemLanguage(index: Int): String;
    public function getItemTextDirection(index: Int): Int;
    public function getItemTooltip(index: Int): String;
    public function getSelectedItems(): lua.Table<Int,Int>;
    public function getVScrollBar(): VscrollBar;
    public function isAnythingSelected(): Bool;
    public function isItemDisabled(index: Int): Bool;
    public function isItemIconTransposed(index: Int): Bool;
    public function isItemSelectable(index: Int): Bool;
    public function isItemTooltipEnabled(index: Int): Bool;
    public function isSelected(index: Int): Bool;
    public function moveItem(from: Int, to: Int): Void;
    public function removeItem(index: Int): Void;
    public function select(index: Int, ?single: Bool): Void;
    public function setItemAutoTranslateMode(index: Int, mode: Int): Void;
    public function setItemCustomBgColor(index: Int, color: Color): Void;
    public function setItemCustomFgColor(index: Int, color: Color): Void;
    public function setItemDisabled(index: Int, disabled: Bool): Void;
    public function setItemIcon(index: Int, texture: Texture2D): Void;
    public function setItemIconModulate(index: Int, color: Color): Void;
    public function setItemIconRegion(index: Int, region: Rect2): Void;
    public function setItemIconTransposed(index: Int, transposed: Bool): Void;
    public function setItemLanguage(index: Int, language: String): Void;
    public function setItemMetadata(index: Int, metadata: Dynamic): Void;
    public function setItemSelectable(index: Int, selectable: Bool): Void;
    public function setItemText(index: Int, text: String): Void;
    public function setItemTextDirection(index: Int, direction: Int): Void;
    public function setItemTooltip(index: Int, tooltip: String): Void;
    public function setItemTooltipEnabled(index: Int, enabled: Bool): Void;
    public function sortItemsByText(): Void;
    @:native("cast")
    public static function toItemList(type: Dynamic): ItemList;
}

abstract ItemListAbstract(ItemList) from ItemList to ItemList {
    @:from
    public static function fromElement(element: kenai.core.Element): ItemListAbstract {
        var itemList = ItemList.toItemList(element);
        if (itemList.isNull()) {
            return null;
        }
        return itemList;
    }
}