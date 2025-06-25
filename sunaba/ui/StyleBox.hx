package lucidware.ui;

import lucidware.core.Resource;
import lucidware.core.Vector2;

@:native("StyleBox")
extern class StyleBox extends Resource {
    public var contentMarginTop: Float;
    public var contentMarginBottom: Float;
    public var contentMarginLeft: Float;
    public var contentMarginRight: Float;
    public function getContentMargin(margin: Int): Float;
    public function getMargin(margin: Int): Float;
    public function getMinimumSize(): Vector2;
    public function getOffset(): Vector2;
    public function setContentMargin(margin: Int, value: Float): Void;
    public function setMargin(margin: Int, value: Float): Void;
    @:native("cast")
    public static function castFrom(res: Dynamic): StyleBox;
}

abstract StyleBoxAbstract(StyleBox) from StyleBox to StyleBox {
    @:from
    public static function fromResource(resource: Resource): StyleBoxAbstract {
        var styleBox = StyleBox.castFrom(resource);
        if (styleBox.isNull()) {
            return null;
        }
        return styleBox;
    }
} // end package lucidware.ui