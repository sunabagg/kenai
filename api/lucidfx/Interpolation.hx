package lucidfx;

enum abstract Interpolation(Int) from Int to Int {
	var nearest = 0;
	var bilinear = 1;
	var cubic = 2;
	var trilinear = 3;
	var lanczos = 4;
}
