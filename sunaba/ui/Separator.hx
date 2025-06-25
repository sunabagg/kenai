package lucidware.ui;

@:native("Separator")
extern class Separator extends Control {
    @:native("cast")
    public static function toSeparator(obj: Dynamic): lucidware.ui.Separator;
}

abstract SeparatorAbstract(Separator) from Separator to Separator {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.Separator {
        var separator = lucidware.ui.Separator.toSeparator(element);
        if (separator.isNull()) {
            return null;
        }
        return separator;
    }
}