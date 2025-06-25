package lucidware.desktop;

@:native("PopupPanel")
extern class PopupPanel extends Popup {
    @:native("cast")
    public static function toPopupPanel(type: Dynamic): PopupPanel;
}

abstract PopupPanelAbstract(PopupPanel) from PopupPanel to PopupPanel {
    @:from
    public static function fromElement(element: lucidware.core.Element): PopupPanelAbstract {
        var panel = PopupPanel.toPopupPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}