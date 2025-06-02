package sunaba.ui;

@:native("HScrollBar")
extern class HScrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): sunaba.ui.HScrollBar;
}