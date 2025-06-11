package sunaba.core;

abstract StringArray(lua.Table<Int, String>) from lua.Table<Int, String> to lua.Table<Int, String> {
    @:to
    public inline function toArray(): Array<T> {
        var table : lua.Table<Int, T> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<T>): StringArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}