package kenai.ui;

@:native("Hseparator")
extern class Hseparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): kenai.ui.Hseparator;
}

abstract HseparatorAbstract(Hseparator) from Hseparator to Hseparator {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Hseparator {
        var hSeparator = kenai.ui.Hseparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}