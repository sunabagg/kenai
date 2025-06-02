package sunaba.ui;

@:native("HSlider")
extern class HSlider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): sunaba.ui.HSlider;
}

abstract HSliderAbstract(HSlider) from HSlider to HSlider {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HSlider {
        var hSlider = sunaba.ui.HSlider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}