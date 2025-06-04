package sunaba.ui;

import sunaba.core.Event;
import sunaba.core.Texture2D;

@:native("TabBar")
extern class TabBar extends Control {
    public var clipTabs: Bool;
    public var currentTab: Int;
    public var deselectEnabled: Bool;
    public var dragToRearrangeEnabled: Bool;
    public var focusMode: Int;
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
}