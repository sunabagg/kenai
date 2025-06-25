package lucidfx.spatial;

@:native("IGeometryInstance")
extern class IGeometryInstance extends IVisualInstance {
    public var castShadow : Int;
    public var giMode : Int;
    public var lightmapScale : Int;
    public var lodBias : Float;
    public var transparancy : Float;
    public var visibilityRangeBegin : Float;
    public var visibilityRangeEnd : Float;
    public var visibilityRangeBeginMargin : Float;
    public var visibilityRangeEndMargin : Float;
    public var visibilityRangeFadeMode : Float;
}