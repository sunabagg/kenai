package sunaba.core;

abstract Vector4Array<T>(lua.Vector<Vector4>) from lua.Vector<Vector4> to lua.Vector<Vector4> {
    @:to
    public inline function toArray(): Array<Vector4> {
        var table : lua.Vector<Vector4> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector4>): Vector4Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}