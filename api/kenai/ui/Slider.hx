package kenai.ui;

import kenai.core.Event;

@:native("Slider")
extern class Slider extends Range {
    public var editable: Bool;
    public var scrollable: Bool;
    public var tickCount: Int;
    public var ticksOnBorders: Bool;
    public var dragEnded: Event;
    public var dragStarted: Event;
    @:native("cast")
    public static function toSlider(obj: Dynamic): kenai.ui.Slider;
}

abstract SliderAbstract(Slider) from Slider to Slider {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Slider {
        var slider = kenai.ui.Slider.toSlider(element);
        if (slider.isNull()) {
            return null;
        }
        return slider;
    }
}
