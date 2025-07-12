package kenai.ui;

@:native("VscrollBar")
extern class VscrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): kenai.ui.VscrollBar;
}

abstract VscrollBarAbstract(VscrollBar) from VscrollBar to VscrollBar {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.VscrollBar {
        var vScrollBar = kenai.ui.VscrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}