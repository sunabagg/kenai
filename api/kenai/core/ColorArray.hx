package kenai.core;

import kenai.core.Color;

abstract ColorArray(kenai.core.Vector<Color>) from kenai.core.Vector<Color> to kenai.core.Vector<Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var table : kenai.core.Vector<Color> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Color>): ColorArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}