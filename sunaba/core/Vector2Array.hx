package lucidware.core;

abstract Vector2Array<T>(lua.Table<Int, Vector2>) from lua.Table<Int, Vector2> to lua.Table<Int, Vector2> {
    @:to
    public inline function toArray(): Array<Vector2> {
        var table : lua.Table<Int, Vector2> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector2>): Vector2Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}
