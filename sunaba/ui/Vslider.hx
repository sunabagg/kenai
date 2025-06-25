package lucidware.ui;

@:native("Vslider")
extern class Vslider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): lucidware.ui.Vslider;
}

abstract VsliderAbstract(Vslider) from Vslider to Vslider {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.Vslider {
        var vSlider = lucidware.ui.Vslider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}