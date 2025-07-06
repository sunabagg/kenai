package sunaba.core;

abstract FloatArray(lua.Vector<Float>) from lua.Vector<Float> to lua.Vector<Float> {
    @:to
    public inline function toArray(): Array<Float> {
        var table : lua.Vector<Float> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Float>): FloatArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}