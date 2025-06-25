package lucidfx.ui;

@:native("Vslider")
extern class Vslider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): lucidfx.ui.Vslider;
}

abstract VsliderAbstract(Vslider) from Vslider to Vslider {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Vslider {
        var vSlider = lucidfx.ui.Vslider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}