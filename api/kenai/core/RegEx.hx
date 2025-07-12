package kenai.core;

import lua.Table;

@:native("RegEx")
extern class RegEx extends BaseObject {
    public function new();
    public function compile(pattern: String, ?showError: Bool): Int;
    public function createFromString(pattern: String, ?showError: Bool): RegEx;
    public function getGroupCount(): Int;
    public function getNames(): StringArray;
    public function getPattern(): String;
    public function isValid(): Bool;
    public function search(subject: String, ?offset: Int, ?end: Int): RegExMatch;
    public function searchAll(subject: String, ?offset: Int, ?end: Int): Vector<RegExMatch>;
    public function sub(subject: String, replacemtn: String, ?all: Bool, ?offset: Int, ?end: Int): String;
}