package sunaba.ui;

import sunaba.core.BaseObject;
import sunaba.core.Texture2D;

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
}