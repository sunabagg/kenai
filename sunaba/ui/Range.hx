package sunaba.ui;

import sunaba.core.Element;

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
    public var sizeFlagsVertical: Int;
    public var step: Float;
    public var value: Float;
    public var changed: sunaba.core.Event;
    public var valueChanged: sunaba.core.Event;
    public function setValueNoSignal(value: Float): Void;
    public function share(with: Element): Void;
    public function unshare(): Void;
    @:native("cast")
    public static function toRange(obj: Dynamic): sunaba.ui.Range;
}