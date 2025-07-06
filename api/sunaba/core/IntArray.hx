package sunaba.core;

abstract IntArray(lua.Vector<Int>) from lua.Vector<Int> to lua.Vector<Int> {
    @:to
    public inline function toArray(): Array<Int> {
        var table : lua.Vector<Int> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Int>): IntArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}