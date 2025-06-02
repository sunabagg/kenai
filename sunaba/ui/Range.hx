package sunaba.ui;

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
}