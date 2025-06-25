package lucidfx;

enum abstract StdHandleType(Int) from Int to Int {
	var invalid = 0;
	var console = 1;
	var file = 2;
	var pipe = 3;
	var unknown = 4;
}
