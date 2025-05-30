package sunaba.desktop;

@:native("PopupPanel")
extern class PopupPanel extends Popup {
    @:native("cast")
    public function toPopupPanel(type: Dynamic): PopupPanel;
}

abstract PopupPanelAbstract(PopupPanel) from PopupPanel to PopupPanel {
    @:from
    public static function fromElement(element: sunaba.core.Element): PopupPanelAbstract {
        var panel = PopupPanel.toPopupPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}