package sunaba.ui;

@:native("HSeparator")
extern class HSeparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): sunaba.ui.HSeparator;
}

abstract HSeparatorAbstract(HSeparator) from HSeparator to HSeparator {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.HSeparator {
        var hSeparator = sunaba.ui.HSeparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}