package lucidfx;

enum abstract InterpolationModeEnum(Int) from Int to Int {
	var linear = 0;
	var constant = 1;
	var cubic = 2;
}
