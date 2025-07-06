package sunaba.core;

import sunaba.core.Color;

abstract ColorArray(sunaba.core.Vector<Color>) from sunaba.core.Vector<Color> to sunaba.core.Vector<Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var table : sunaba.core.Vector<Color> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Color>): ColorArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}