package sunaba.ui;

@:native("Vslider")
extern class Vslider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): sunaba.ui.Vslider;
}

abstract VsliderAbstract(Vslider) from Vslider to Vslider {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Vslider {
        var vSlider = sunaba.ui.Vslider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}