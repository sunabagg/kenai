package sunaba.ui;

@:native("HScrollBar")
extern class HScrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): sunaba.ui.HScrollBar;
}

abstract HScrollBarAbstract(HScrollBar) from HScrollBar to HScrollBar {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HScrollBar {
        var hScrollBar = sunaba.ui.HScrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}