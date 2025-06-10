package sunaba.ui;

import sunaba.core.Color;
import sunaba.core.BaseObject;
import sunaba.core.Texture2D;
import sunaba.core.Font;
import sunaba.core.Rect2;
import sunaba.core.Variant;

@:native("TreeItem")
extern class TreeItem extends BaseObject {
    public var collapsed: Bool;
    public var customMinimumHeight: Int;
    public var disableFolding: Bool;
    public var visible: Bool;
    public function addButton(column: Int, button: Texture2D, ?id: Int, ?disabled: Bool, ?tooltipText: String): Void;
    public function addChild(item: TreeItem): Void;
    public function clearButtons(): Void;
    public function clearCustomBgColor(column: Int): Void;
    public function clearCustomColor(column: Int): Void;
    public function createChild(?index: Int): TreeItem;
    public function deselect(column: Int): Void;
    public function eraseButton(column: Int, idx: Int): Void;
    public function getAutoTranslateMode(column: Int): Int;
    public function getAutowrapMode(column: Int): Int;
    public function getButton(column: Int, idx: Int): Texture2D;
    public function getButtonById(column: Int, id: Int): Int;
    public function getButtonColor(column: Int, idx: Int): Color;
    public function getButtonCount(column: Int): Int;
    public function getButtonId(column: Int, idx: Int): Int;
    public function getButtonTooltipText(column: Int, idx: Int): String;
    public function getCellMode(column: Int): Int;
    public function getChild(index: Int): TreeItem;
    public function getChildCount(): Int;
    public function getChildren(): Array<TreeItem>;
    public function getCustomBgColor(column: Int): Color;
    public function getCustomColor(column: Int): Color;
    public function getCustomFont(column: Int): Font;
    public function getCustomFontSize(column: Int): Int;
    public function getExpandRight(column: Int): Bool;
    public function getFirstChild(): TreeItem;
    public function getIcon(column: Int): Texture2D;
    public function getIconMaxWidth(column: Int): Int;
    public function getIconModulate(column: Int): Color;
    public function getIconOverlay(column: Int): Texture2D;
    public function getIconRegion(column: Int): Rect2;
    public function getIndex(): Int;
    public function getLanguage(column: Int): String;
    public function getMetadata(column: Int): Variant;
    public function getNext(): TreeItem;
    public function getNextInTree(): TreeItem;
    public function getNextVisible(): TreeItem;
}