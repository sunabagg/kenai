package sunaba.ui;

@:native("TabBar")
extern class TabBar extends Container {
    public var clipTabs: Bool;
    public var currentTab: Int;
    public var deselectEnabled: Bool;
}