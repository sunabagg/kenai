package sunaba.core;

abstract FloatArray(sunaba.core.Vector<Float>) from sunaba.core.Vector<Float> to sunaba.core.Vector<Float> {
    @:to
    public inline function toArray(): Array<Float> {
        var table : sunaba.core.Vector<Float> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Float>): FloatArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}