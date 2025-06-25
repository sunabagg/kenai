package lucidware.ui;

@:native("Hseparator")
extern class Hseparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): lucidware.ui.Hseparator;
}

abstract HseparatorAbstract(Hseparator) from Hseparator to Hseparator {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.Hseparator {
        var hSeparator = lucidware.ui.Hseparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}