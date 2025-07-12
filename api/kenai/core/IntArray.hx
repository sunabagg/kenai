package kenai.core;

abstract IntArray(kenai.core.Vector<Int>) from kenai.core.Vector<Int> to kenai.core.Vector<Int> {
    @:to
    public inline function toArray(): Array<Int> {
        var table : kenai.core.Vector<Int> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Int>): IntArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}