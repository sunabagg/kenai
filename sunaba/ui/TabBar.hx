package sunaba.ui;

@:native("TabBar")
extern class TabBar extends Control {
    public var clipTabs: Bool;
    public var currentTab: Int;
    public var deselectEnabled: Bool;
    public var dragToRearrangeEnabled: Bool;
    public var focusMode: Int;
    public var maxTabWidth: Int;
}