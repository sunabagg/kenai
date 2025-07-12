package kenai.ui;

@:native("Hslider")
extern class Hslider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): kenai.ui.Hslider;
}

abstract HsliderAbstract(Hslider) from Hslider to Hslider {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Hslider {
        var hSlider = kenai.ui.Hslider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}