package lucidfx.ui;

@:native("Separator")
extern class Separator extends Control {
    @:native("cast")
    public static function toSeparator(obj: Dynamic): lucidfx.ui.Separator;
}

abstract SeparatorAbstract(Separator) from Separator to Separator {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Separator {
        var separator = lucidfx.ui.Separator.toSeparator(element);
        if (separator.isNull()) {
            return null;
        }
        return separator;
    }
}