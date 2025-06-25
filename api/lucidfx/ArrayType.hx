package lucidfx;

enum abstract ArrayType(Int) from Int to Int {
	var vertex = 0;
	var normal = 1;
	var tangent = 2;
	var color = 3;
	var texUv = 4;
	var texUv2 = 5;
	var custom0 = 6;
	var custom1 = 7;
	var custom2 = 8;
	var custom3 = 9;
	var bones = 10;
	var weights = 11;
	var index = 12;
	var max = 13;
}
