package lucidware.core;

abstract IntArray(lua.Table<Int, Int>) from lua.Table<Int, Int> to lua.Table<Int, Int> {
    @:to
    public inline function toArray(): Array<Int> {
        var table : lua.Table<Int, Int> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Int>): IntArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}