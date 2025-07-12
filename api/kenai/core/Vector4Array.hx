package kenai.core;

abstract Vector4Array<T>(kenai.core.Vector<Vector4>) from kenai.core.Vector<Vector4> to kenai.core.Vector<Vector4> {
    @:to
    public inline function toArray(): Array<Vector4> {
        var table : kenai.core.Vector<Vector4> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector4>): Vector4Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}