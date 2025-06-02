package sunaba.ui;

@:native("VSlider")
extern class VSlider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): sunaba.ui.VSlider;
}

abstract VSliderAbstract(VSlider) from VSlider to VSlider {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VSlider {
        var vSlider = sunaba.ui.VSlider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}