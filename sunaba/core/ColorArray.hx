package sunaba.core;

import sunaba.core.Color;

abstract ColorArray(lua.Table<Int, Color>) from lua.Table<Int, Color> to lua.Table<Int, Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var result = new Array<Color>(this.size());
        for (i in 0...this.size()) {
            result[i] = this.get(i);
        }
        return result;
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