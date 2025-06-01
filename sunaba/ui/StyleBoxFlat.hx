package sunaba.ui;

import sunaba.core.Vector2;

@:native("StyleBoxFlat")
extern class StyleBoxFlat extends StyleBox {
    public var antiAliasing: Bool;
    public var antiAliasingSize: Float;
    public var bgColor: Color;
    public var borderBlend: Bool;
    public var borderColor: Color;
    public var borderWidthBottom: Int;
    public var borderWidthLeft: Int;
    public var borderWidthRight: Int;
    public var borderWidthTop: Int;
    public var cornerRadiusBottomLeft: Int;
    public var cornerRadiusBottomRight: Int;
    public var cornerRadiusTopLeft: Int;
    public var cornerRadiusTopRight: Int;
    public var drawCenter: Bool;
    public var ExpandMarginBottom: Int;
    public var ExpandMarginLeft: Int;
    public var ExpandMarginRight: Int;
    public var ExpandMarginTop: Int;
    public var shadowColor: Color;
    public var shadowOffset: Vector2;
    public var skew: Vector2;
    public function getBorderWidth(side: Int): Int;
    public function getBorderWidthMin(): Int;
    public function getCornerRadius(corner: Int): Int;
    public function getExpandMargin(margin: Int): Int;
    public function setBorderWidth(side: Int, value: Int): Void;
    public function setBorderWidthAll(value: Int): Void;
    public function setCornerRadius(corner: Int, value: Int): Void;
    public function setCornerRadiusAll(value: Int): Void;
    public function setExpandMargin(margin: Int, value: Int): Void;
    public function setExpandMarginAll(value: Int): Void;
    @:native("cast")
    public static function castFrom(res: Dynamic): StyleBoxFlat;
}

abstract StyleBoxFlatAbstract(StyleBoxFlat) from StyleBoxFlat to StyleBoxFlat {
    @:from
    public static function fromResource(resource: Resource): StyleBoxFlatAbstract {
        var styleBoxFlat = StyleBoxFlat.castFrom(resource);
        if (styleBoxFlat.isNull()) {
            return null;
        }
        return styleBoxFlat;
    }
} // end package sunaba.ui