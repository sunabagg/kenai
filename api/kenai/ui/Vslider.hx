package kenai.ui;

@:native("Vslider")
extern class Vslider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): kenai.ui.Vslider;
}

abstract VsliderAbstract(Vslider) from Vslider to Vslider {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Vslider {
        var vSlider = kenai.ui.Vslider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}