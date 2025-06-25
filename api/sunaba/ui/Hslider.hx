package sunaba.ui;

@:native("Hslider")
extern class Hslider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): sunaba.ui.Hslider;
}

abstract HsliderAbstract(Hslider) from Hslider to Hslider {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Hslider {
        var hSlider = sunaba.ui.Hslider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}