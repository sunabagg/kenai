package kenai.ui;

import kenai.core.Event;
import kenai.desktop.Popup;
import kenai.core.Texture2D;
import kenai.core.Vector2;
import kenai.core.Variant;
import kenai.core.Element;

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
    public var tabClicked: Event;
    public var tabHovered: Event;
    public var tabSelected: Event;
    public function getCurrentTabControl(): Control;
    public function getPopup() : Popup;
    public function getPreviousTab(): Int;
    public function getTabBar(): TabBar;
    public function getTabButtonIcon(tab: Int): Texture2D;
    public function getTabControl(tab: Int): Control;
    public function getTabCount(): Int;
    public function getTabIcon(tab: Int): Texture2D;
    public function getTabIconMaxWidth(tab: Int): Int;
    public function getTabIdxAtPoint(point: Vector2): Int;
    public function getTabIdxFromControl(control: Control): Int;
    public function getTabMetadata(tab: Int): Variant;
    public function getTabTitle(tab: Int): String;
    public function getTabTooltip(tab: Int): String;
    public function isTabDisabled(tab: Int): Bool;
    public function isTabHidden(tab: Int): Bool;
    public function selectNextAvailable(): Bool;
    public function selectPreviousAvailable(): Bool;
    public function setPopup(popup: Popup): Void;
    public function setTabButtonIcon(tab: Int, icon: Texture2D): Void;
    public function setTabDisabled(tab: Int, disabled: Bool): Void;
    public function setTabHidden(tab: Int, hidden: Bool): Void;
    public function setTabIcon(tab: Int, icon: Texture2D): Void;
    public function setTabIconMaxWidth(tab: Int, width: Int): Void;
    public function setTabMetadata(tab: Int, metadata: Variant): Void;
    public function setTabTitle(tab: Int, title: String): Void;
    public function setTabTooltip(tab: Int, tooltip: String): Void;
    @:native("cast")
    public static function toTabContainer(obj:Dynamic): TabContainer;
}

abstract TabConatinerAbstract(TabContainer) from TabContainer to TabContainer {
    @:from
    public static function fromElement(element: Element): ControlAbstract {
        var tbContainer = TabContainer.toTabContainer(element);
        if (tbContainer.isNull()) {
            return null;
        }
        return tbContainer;
    }
}