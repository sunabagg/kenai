package sunaba.ui;

import sunaba.core.Vector2;
import sunaba.core.Texture2D;
import sunaba.core.Color;
import sunaba.core.Element;

@:native("TextureProgressBar")
extern class TextureProgressBar extends Range {
    public var fillMode: Int;
    public var ninePatchStretch: Bool;
    public var radialCenterOffset: Vector2;
    public var radialFillDegrees: Float;
    public var radialInitialAngle: Float;
    public var stretchMarginBottom: Int;
    public var stretchMarginLeft: Int;
    public var stretchMarginRight: Int;
    public var stretchMarginTop: Int;
    public var textureOver: Texture2D;
    public var textureProgress: Texture2D;
    public var textureUnder: Texture2D;
    public var tintOver: Color;
    public var tintProgress: Color;
    public var tintUnder: Color;
    public function getStretchMargin(side: Int): Int;
    public function setStretchMargin(side: Int, margin: Int): Void;
    @:native("cast")
    public static function toTextureProgressBar(obj: Dynamic): TextureProgressBar;
}

abstract TextureProgressBarAbstract(TextureProgressBar) from TextureProgressBar to TextureProgressBar {
    @:from
    public static function fromElement(e: Element): TextureProgressBarAbstract {
        var tProgressBar = TextureProgressBar.toTextureProgressBar(e);
        if (tProgressBar.isNull()) {
            return null;
        }
        return tProgressBar;
    }
}