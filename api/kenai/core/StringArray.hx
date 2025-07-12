package kenai.core;

import lua.Table;

abstract StringArray(Vector<String>) from Vector<String> to Vector<String> {
    @:to
    public inline function toArray(): Array<String> {
        return this.toArray();
    }

    @:from
    public static function fromArray(array: Array<String>): StringArray {
        var table = Table.fromArray(array);
        var result : StringArray = Vector.fromTable(table);
        return result;
    }
}