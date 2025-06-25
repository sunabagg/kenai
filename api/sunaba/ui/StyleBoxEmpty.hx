package sunaba.ui;

import sunaba.core.Resource;

@:native("StyleBoxEmpty")
extern class StyleBoxEmpty extends StyleBox {
    @:native("cast")
    public static function castFrom(res: Dynamic): StyleBoxEmpty;
}

abstract StyleBoxEmptyAbstract(StyleBoxEmpty) from StyleBoxEmpty to StyleBoxEmpty {
    @:from
    public static function fromResource(resource: Resource): StyleBoxEmptyAbstract {
        var styleBoxEmpty = StyleBoxEmpty.castFrom(resource);
        if (styleBoxEmpty.isNull()) {
            return null;
        }
        return styleBoxEmpty;
    }
} // end package sunaba.ui