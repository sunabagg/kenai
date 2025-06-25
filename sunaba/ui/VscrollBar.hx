package lucidware.ui;

@:native("VscrollBar")
extern class VscrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): lucidware.ui.VscrollBar;
}

abstract VscrollBarAbstract(VscrollBar) from VscrollBar to VscrollBar {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.VscrollBar {
        var vScrollBar = lucidware.ui.VscrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}