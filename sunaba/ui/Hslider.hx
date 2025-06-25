package lucidware.ui;

@:native("Hslider")
extern class Hslider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): lucidware.ui.Hslider;
}

abstract HsliderAbstract(Hslider) from Hslider to Hslider {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.Hslider {
        var hSlider = lucidware.ui.Hslider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}