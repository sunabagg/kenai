package lucidware.ui;

import lucidware.core.Event;
import lucidware.core.Texture2D;
import lucidware.core.Variant;
import lucidware.core.Rect2;
import lucidware.core.Vector2;

@:native("TabBar")
extern class TabBar extends Control {
    public var clipTabs: Bool;
    public var currentTab: Int;
    public var deselectEnabled: Bool;
    public var dragToRearrangeEnabled: Bool;
    public var maxTabWidth: Int;
    public var scrollToSelected: Bool;
    public var scrollingEnabled: Bool;
    public var selectWithRmb: Bool;
    public var tabAlignment: Int;
    public var tabCloseDisplayPolicy: Int;
    public var tabCount: Int;
    public var tabsRearrangeGroup: Int;
    public var activeTabRearrange: Event;
    public var tabButtonPressed: Event;
    public var tabChanged: Event;
    public var tabClicked: Event;
    public var tabClosePressed: Event;
    public var tabHovered: Event;
    public var tabRmbClicked: Event;
    public var tabSelected: Event;
    public function addTab(name: String, ?icon: Texture2D): Void;
    public function clearTabs(): Void;
    public function ensureTabVisible(tab: Int): Void;
    public function getOffsetButtonsVisible(): Bool;
    public function getPreviousTab(): Int;
    public function getTabButtonIcon(tab: Int): Texture2D;
    public function getTabIcon(tab: Int): Texture2D;
    public function getTabIconMaxWidth(tab: Int): Int;
    public function getTabIdxAtPoint(point: Vector2): Int;
    public function getTabLanguage(tab: Int): String;
    public function getTabMetadata(tab: Int): Variant;
    public function getTabOffset(): Int;
    public function getTabRect(tab: Int): Rect2;
    public function getTabTextDirection(tab: Int): Int;
    public function getTabTitle(tab: Int): String;
    public function getTabTooltip(tab: Int): String;
    public function isTabDisabled(tab: Int): Bool;
    public function isTabHidden(tab: Int): Bool;
    public function moveTab(from: Int, to: Int): Void;
    public function removeTab(tab: Int): Void;
    public function selectNextAvailable(): Bool;
    public function selectPreviousAvailable(): Bool;
    public function setTabButtonIcon(tab: Int, icon: Texture2D): Void;
    public function setTabDisabled(tab: Int, disabled: Bool): Void;
    public function setTabHidden(tab: Int, hidden: Bool): Void;
    public function setTabIcon(tab: Int, icon: Texture2D): Void;
    public function setTabIconMaxWidth(tab: Int, width: Int): Void;
    public function setTabLanguage(tab: Int, language: String): Void;
    public function setTabMetadata(tab: Int, metadata: Variant): Void;
    public function setTabTextDirection(tab: Int, direction: Int): Void;
    public function setTabTitle(tab: Int, title: String): Void;
    public function setTabTooltip(tab: Int, tooltip: String): Void;
    @:native("cast")
    public static function toTabBar(obj: Dynamic): TabBar;
}

abstract TabBarAbstract(TabBar) from TabBar to TabBar {
    @:from
    public static function fromElement(element: lucidware.core.Element): TabBarAbstract {
        var tabbar = TabBar.toTabBar(element);
        if (tabbar.isNull()) {
            return null;
        }
        return tabbar;
    }
}