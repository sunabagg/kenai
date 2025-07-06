package sunaba.core;

abstract Vector3Array<T>(sunaba.core.Vector<Vector3>) from sunaba.core.Vector<Vector3> to sunaba.core.Vector<Vector3> {
    @:to
    public inline function toArray(): Array<Vector3> {
        var table : sunaba.core.Vector<Vector3> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector3>): Vector3Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}