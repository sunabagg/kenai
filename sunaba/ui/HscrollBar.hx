package lucidware.ui;

@:native("HscrollBar")
extern class HscrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): lucidware.ui.HscrollBar;
}

abstract HscrollBarAbstract(HscrollBar) from HscrollBar to HscrollBar {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.HscrollBar {
        var hScrollBar = lucidware.ui.HscrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}