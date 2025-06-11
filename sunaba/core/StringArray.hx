package sunaba.core;

abstract StringArray<T>(lua.Table<Int, T>) from lua.Table<Int, T> to lua.Table<Int, T> {
    @:to
    public inline function toArray(): Array<T> {
        var table : lua.Table<Int, T> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<T>): StringArray<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}