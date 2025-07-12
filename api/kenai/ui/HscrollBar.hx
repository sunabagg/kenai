package kenai.ui;

@:native("HscrollBar")
extern class HscrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): kenai.ui.HscrollBar;
}

abstract HscrollBarAbstract(HscrollBar) from HscrollBar to HscrollBar {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.HscrollBar {
        var hScrollBar = kenai.ui.HscrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}