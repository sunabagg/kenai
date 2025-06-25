package lucidware.ui;

@:native("StyleBoxLine")
extern class StyleBoxLine extends StyleBox {
    public var color: Color;
    public var growBegin: Float;
    public var growEnd: Float;
    public var thickness: Float;
    public var vertical: Bool;
    @:native("cast")
    public static function castFrom(res: Dynamic): StyleBoxLine;
}

abstract StyleBoxLineAbstract(StyleBoxLine) from StyleBoxLine to StyleBoxLine {
    @:from
    public static function fromResource(resource: Resource): StyleBoxLineAbstract {
        var styleBoxLine = StyleBoxLine.castFrom(resource);
        if (styleBoxLine.isNull()) {
            return null;
        }
        return styleBoxLine;
    }
} // end package lucidware.ui