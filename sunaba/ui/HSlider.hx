package sunaba.ui;

@:native("HSlider")
extern class HSlider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): sunaba.ui.HSlider;
}