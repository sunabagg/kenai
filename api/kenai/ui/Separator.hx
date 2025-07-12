package kenai.ui;

@:native("Separator")
extern class Separator extends Control {
    @:native("cast")
    public static function toSeparator(obj: Dynamic): kenai.ui.Separator;
}

abstract SeparatorAbstract(Separator) from Separator to Separator {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Separator {
        var separator = kenai.ui.Separator.toSeparator(element);
        if (separator.isNull()) {
            return null;
        }
        return separator;
    }
}