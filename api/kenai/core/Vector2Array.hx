package kenai.core;

abstract Vector2Array<T>(kenai.core.Vector<Vector2>) from kenai.core.Vector<Vector2> to kenai.core.Vector<Vector2> {
    @:to
    public inline function toArray(): Array<Vector2> {
        var table : kenai.core.Vector<Vector2> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector2>): Vector2Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}
