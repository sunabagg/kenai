package sunaba.ui;

import sunaba.core.Event;

@:native("TabContainer")
extern class TabContainer extends Container {
    public var allTabsInFront: Bool;
    public var clipTabs: Bool;
    public var currentTab: Int;
    public var deselectEnabled: Bool;
    public var dragToRearrangeEnabled: Bool;
    public var tabAlignment: Int;
    public var tabFocusMode: Int;
    public var tabsPosition: Int;
    public var tabsRearrangeGroup: Int;
    public var tabsVisible: Bool;
    public var useHiddenTabsForMinSize: Bool;
    public var activeTabRearranged: Event;
    public var prePopupPressed: Event;
    public var tabButtonPressed: Event;
    public var tabChanged: Event;
}