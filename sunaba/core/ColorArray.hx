package sunaba.core;

import sunaba.core.Color;

abstract ColorArray(lua.Table<Int, Color>) from lua.Table<Int, Color> to lua.Table<Int, Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var table : lua.Table<Int, Color> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Color>): ColorArray {
        var result = new lua.Table<Int, Color>();
        for (i in 0...array.length) {
            result[i] = array[i];
        }
        return result;
    }
}