package lucidfx.ui;

@:native("Hseparator")
extern class Hseparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): lucidfx.ui.Hseparator;
}

abstract HseparatorAbstract(Hseparator) from Hseparator to Hseparator {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Hseparator {
        var hSeparator = lucidfx.ui.Hseparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}