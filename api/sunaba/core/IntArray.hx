package sunaba.core;

abstract IntArray(sunaba.core.Vector<Int>) from sunaba.core.Vector<Int> to sunaba.core.Vector<Int> {
    @:to
    public inline function toArray(): Array<Int> {
        var table : sunaba.core.Vector<Int> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Int>): IntArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}