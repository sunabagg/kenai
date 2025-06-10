package sunaba.ui;

import sunaba.core.Vector2;

@:native("TextureProgressBar")
extern class TextureProgressBar extends Range {
    public var fillMode: Int;
    public var mouseFilter: Int;
    public var ninePatchStretch: Bool;
    public var radialCenterOffset: Vector2;
    public var radialFillDegrees: Float;
    public var radialInitialAngle: Float;
    public var sizeFlagsVertical: Int;
    public var step: Float;
}