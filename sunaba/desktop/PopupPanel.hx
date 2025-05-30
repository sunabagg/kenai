package sunaba.desktop;

@:native("PopupPanel")
extern class PopupPanel extends Popup {
    @:native("cast")
    public function toPopupPanel(type: Dynamic): PopupPanel;
}