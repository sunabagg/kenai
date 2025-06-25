package lucidfx.ui;

@:native("Hslider")
extern class Hslider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): lucidfx.ui.Hslider;
}

abstract HsliderAbstract(Hslider) from Hslider to Hslider {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Hslider {
        var hSlider = lucidfx.ui.Hslider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}