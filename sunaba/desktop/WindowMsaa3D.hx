package lucidfx..desktop;

enum abstract WindowMsaa3D(Int) from Int to Int {
	var disabled = 0;
	var msaa2x = 1;
	var msaa4x = 2;
	var msaa8x = 3;
	var max = 4;
}
