package lucidfx.ui;

import lucidfx.core.Element;

@:native("Range")
extern class Range extends Control {
    public var allowGreater: Bool;
    public var allowLesser: Bool;
    public var expEdit: Bool;
    public var maxValue: Float;
    public var minValue: Float;
    public var page: Float;
    public var ratio: Float;
    public var rounded: Bool;
    public var step: Float;
    public var value: Float;
    public var changed: lucidfx.core.Event;
    public var valueChanged: lucidfx.core.Event;
    public function setValueNoSignal(value: Float): Void;
    public function share(with: Element): Void;
    public function unshare(): Void;
    @:native("cast")
    public static function toRange(obj: Dynamic): lucidfx.ui.Range;
}

abstract RangeAbstract(Range) from Range to Range {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Range {
        var range = lucidfx.ui.Range.toRange(element);
        if (range.isNull()) {
            return null;
        }
        return range;
    }
}