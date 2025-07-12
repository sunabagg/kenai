package kenai.desktop;

import kenai.core.Element;
import kenai.core.Texture2D;
import kenai.core.Event;
import kenai.core.Rect2;

@:native("StatusIndicator")
extern class StatusIndicator extends Element {
    public var icon: Texture2D;
    public var menu: String;
    public var tooltip: String;
    public var visible: Bool;
    public var pressed: Event;
    public function getRect(): Rect2;
    @:native("cast")
    public static function toStatusIndicator(obj:Any): StatusIndicator;
} 

abstract StatusIndicatorAbstract(StatusIndicator) from StatusIndicator to StatusIndicator {
    @:from
    public static function fromElement(e:Element): StatusIndicatorAbstract {
        var indicator = StatusIndicator.toStatusIndicator(e);
        if (indicator.isNull()) {
            return null;
        }
        return indicator;
    }
}