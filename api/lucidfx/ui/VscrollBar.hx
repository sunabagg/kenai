package lucidfx.ui;

@:native("VscrollBar")
extern class VscrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): lucidfx.ui.VscrollBar;
}

abstract VscrollBarAbstract(VscrollBar) from VscrollBar to VscrollBar {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.VscrollBar {
        var vScrollBar = lucidfx.ui.VscrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}