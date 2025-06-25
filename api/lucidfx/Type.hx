package lucidfx;

enum abstract Type(Int) from Int to Int {
	var vertex = 0;
	var fragment = 1;
	var light = 2;
	var start = 3;
	var process = 4;
	var collide = 5;
	var startCustom = 6;
	var processCustom = 7;
	var sky = 8;
	var fog = 9;
	var max = 10;
}
