package sunaba.ui;

@:native("Separator")
extern class Separator extends Control {
    @:native("cast")
    public static function toSeparator(obj: Dynamic): sunaba.ui.Separator;
}

abstract SeparatorAbstract(Separator) from Separator to Separator {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Separator {
        var separator = sunaba.ui.Separator.toSeparator(element);
        if (separator.isNull()) {
            return null;
        }
        return separator;
    }
}