package kenai.core;

abstract Vector3Array<T>(kenai.core.Vector<Vector3>) from kenai.core.Vector<Vector3> to kenai.core.Vector<Vector3> {
    @:to
    public inline function toArray(): Array<Vector3> {
        var table : kenai.core.Vector<Vector3> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector3>): Vector3Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}