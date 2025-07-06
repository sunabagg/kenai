package sunaba.core;

abstract Vector3Array<T>(lua.Vector<Vector3>) from lua.Vector<Vector3> to lua.Vector<Vector3> {
    @:to
    public inline function toArray(): Array<Vector3> {
        var table : lua.Vector<Vector3> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Vector3>): Vector3Array<T> {
        var result = lua.Table.fromArray(array);
        return result;
    }
}