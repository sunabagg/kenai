package sunaba.core;

@:native("Gradient")
extern class Gradient extends Resource {
    public var colors: lua.Table<Int, Color>;
    public var interpolationColorSpace: Int;
    public var interpolationMode: Int;
    public var offsets: lua.Table<Int, Float>;
    public function addPoint(offset: Float, color: Color) : Void;
    public function getColor(point: Float) : Color;
    public function getOffset(point: Int) : Float;
    public function getPointCount() : Int;
    public function removePoint(point: Int) : Void;
    public function reverse() : Void;
    public function sample(point: Float) : Color;
    public function setColor(point: Int, color: Color) : Void;
    public function setOffset(point: Int, offset: Float) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Gradient;
}

abstract GradientAbstract(Gradient) from Gradient to Gradient {
    @:from
    public static function fromResource(resource: Resource) : GradientAbstract {
        var gradient = Gradient.castFrom(resource);
        if (gradient.isNull()) {
            return null;
        }
        return gradient;
    } 
}