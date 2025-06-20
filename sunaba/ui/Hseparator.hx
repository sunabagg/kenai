package sunaba.ui;

@:native("Hseparator")
extern class Hseparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): sunaba.ui.Hseparator;
}

abstract HseparatorAbstract(Hseparator) from Hseparator to Hseparator {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Hseparator {
        var hSeparator = sunaba.ui.Hseparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}