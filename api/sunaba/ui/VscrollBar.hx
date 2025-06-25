package sunaba.ui;

@:native("VscrollBar")
extern class VscrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): sunaba.ui.VscrollBar;
}

abstract VscrollBarAbstract(VscrollBar) from VscrollBar to VscrollBar {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VscrollBar {
        var vScrollBar = sunaba.ui.VscrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}