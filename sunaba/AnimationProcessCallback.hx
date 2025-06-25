package lucidfx;

enum abstract AnimationProcessCallback(Int) from Int to Int {
	var physics = 0;
	var idle = 1;
	var manual = 2;
}
