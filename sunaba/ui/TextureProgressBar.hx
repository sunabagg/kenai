package sunaba.ui;

import sunaba.core.Vector2;
import sunaba.core.Texture2D;

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
    public var stretchMarginBottom: Float;
    public var stretchMarginLeft: Float;
    public var stretchMarginRight: Float;
    public var stretchMarginTop: Float;
    public var textureOver: Texture2D;
    public var textureProgress: Texture2D;
    public var textureUnder: Texture2D;
}