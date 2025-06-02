package sunaba.ui;

@:native("VScrollBar")
extern class VScrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): sunaba.ui.VScrollBar;
}

abstract VScrollBarAbstract(VScrollBar) from VScrollBar to VScrollBar {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VScrollBar {
        var vScrollBar = sunaba.ui.VScrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}