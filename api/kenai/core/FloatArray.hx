package kenai.core;

abstract FloatArray(kenai.core.Vector<Float>) from kenai.core.Vector<Float> to kenai.core.Vector<Float> {
    @:to
    public inline function toArray(): Array<Float> {
        var table : kenai.core.Vector<Float> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Float>): FloatArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}