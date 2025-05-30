package sunaba.desktop;

import sunaba.core.Event;

@:native("Popup")
extern class Popup extends Window {
    public var popupHide: Event;
    @:native("cast")
    public function toPopup(type: Dynamic): Popup;
}