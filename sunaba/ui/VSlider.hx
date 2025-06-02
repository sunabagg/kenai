package sunaba.ui;

@:native("VSlider")
extern class VSlider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): sunaba.ui.VSlider;
}