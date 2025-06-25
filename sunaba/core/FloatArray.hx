package lucidfx.core;

abstract FloatArray(lua.Table<Int, Float>) from lua.Table<Int, Float> to lua.Table<Int, Float> {
    @:to
    public inline function toArray(): Array<Float> {
        var table : lua.Table<Int, Float> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Float>): FloatArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}