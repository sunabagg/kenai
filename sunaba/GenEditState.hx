package lucidfx;

enum abstract GenEditState(Int) from Int to Int {
	var disabled = 0;
	var instance = 1;
	var main = 2;
	var mainInherited = 3;
}
