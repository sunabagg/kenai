package sunaba.core;

abstract Vector4Array<T>(sunaba.core.Vector<Vector4>) from sunaba.core.Vector<Vector4> to sunaba.core.Vector<Vector4> {
    @:to
    public inline function toArray(): Array<Vector4> {
        var table : sunaba.core.Vector<Vector4> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector4>): Vector4Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}