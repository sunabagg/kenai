package lucidfx;

enum abstract Capabilities(Int) from Int to Int {
	var none = 0;
	var mono = 1;
	var stereo = 2;
	var quad = 4;
	var vr = 8;
	var ar = 16;
	var external = 32;
}
