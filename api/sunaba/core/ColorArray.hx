package sunaba.core;

import sunaba.core.Color;

abstract ColorArray(lua.Vector<Color>) from lua.Vector<Color> to lua.Vector<Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var table : lua.Vector<Color> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Color>): ColorArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}