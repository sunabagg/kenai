package sunaba.ui;

import sunaba.core.Event;

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
}