package lucidfx.ui;

@:native("HscrollBar")
extern class HscrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): lucidfx.ui.HscrollBar;
}

abstract HscrollBarAbstract(HscrollBar) from HscrollBar to HscrollBar {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.HscrollBar {
        var hScrollBar = lucidfx.ui.HscrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}