package lucidfx.ui;

import lucidfx.core.Color;
import lucidfx.core.Rect2;
import lucidfx.core.Texture2D;

@:native("StyleBoxTexture")
extern class StyleBoxTexture extends StyleBox {
    public var axisStretchHorizontal: Bool;
    public var axisStretchVertical: Bool;
    public var drawCenter: Bool;
    public var expandMarginBottom: Float;
    public var expandMarginLeft: Float;
    public var expandMarginRight: Float;
    public var expandMarginTop: Float;
    public var modulateColor: Color;
    public var regionRect: Rect2;
    public var texture: Texture2D;
    public var textureMarginBottom: Float;
    public var textureMarginLeft: Float;
    public var textureMarginRight: Float;
    public var textureMarginTop: Float;
    public function getExpandMargin(margin: Int): Float;
    public function getTextureMargin(margin: Int): Float;
    public function setExpandMargin(margin: Int, value: Float): Void;
    public function setExpandMarginAll(value: Float): Void;
    public function setTextureMargin(margin: Int, value: Float): Void;
    public function setTextureMarginAll(value: Float): Void;
    @:native("cast")
    public static function castFrom(res: Dynamic): StyleBoxTexture;
}

abstract StyleBoxTextureAbstract(StyleBoxTexture) from StyleBoxTexture to StyleBoxTexture {
    @:from
    public static function fromResource(resource: Resource): StyleBoxTextureAbstract {
        var styleBoxTexture = StyleBoxTexture.castFrom(resource);
        if (styleBoxTexture.isNull()) {
            return null;
        }
        return styleBoxTexture;
    }
} // end package lucidfx.ui