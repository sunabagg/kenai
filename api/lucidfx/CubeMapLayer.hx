package lucidfx;

enum abstract CubeMapLayer(Int) from Int to Int {
	var left = 0;
	var right = 1;
	var bottom = 2;
	var top = 3;
	var front = 4;
	var back = 5;
}
