package sunaba;

enum abstract Interpolation(Int) {
	var Nearest = 0;
	var Bilinear = 1;
	var Cubic = 2;
	var Trilinear = 3;
	var Lanczos = 4;
}
