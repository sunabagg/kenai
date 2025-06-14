package sunaba;

enum abstract Capabilities(Int) {
	var None = 0;
	var Mono = 1;
	var Stereo = 2;
	var Quad = 4;
	var Vr = 8;
	var Ar = 16;
	var External = 32;
}
