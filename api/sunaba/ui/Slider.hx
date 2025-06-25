package sunaba.ui;

import sunaba.core.Event;

@:native("Slider")
extern class Slider extends Range {
    public var editable: Bool;
    public var scrollable: Bool;
    public var tickCount: Int;
    public var ticksOnBorders: Bool;
    public var dragEnded: Event;
    public var dragStarted: Event;
    @:native("cast")
    public static function toSlider(obj: Dynamic): sunaba.ui.Slider;
}

abstract SliderAbstract(Slider) from Slider to Slider {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Slider {
        var slider = sunaba.ui.Slider.toSlider(element);
        if (slider.isNull()) {
            return null;
        }
        return slider;
    }
}
