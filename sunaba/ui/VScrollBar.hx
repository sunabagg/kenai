package sunaba.ui;

@:native("VScrollBar")
extern class VScrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): sunaba.ui.VScrollBar;
}
