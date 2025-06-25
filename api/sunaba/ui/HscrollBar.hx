package sunaba.ui;

@:native("HscrollBar")
extern class HscrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): sunaba.ui.HscrollBar;
}

abstract HscrollBarAbstract(HscrollBar) from HscrollBar to HscrollBar {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HscrollBar {
        var hScrollBar = sunaba.ui.HscrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}