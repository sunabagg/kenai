package lucidfx;

enum abstract ColorModeType(Int) from Int to Int {
	var rgb = 0;
	var hsv = 1;
	var raw = 2;
	var okhsl = 3;
}
