package lucidware;

enum abstract EmissionShapeEnum(Int) from Int to Int {
	var point = 0;
	var sphere = 1;
	var sphereSurface = 2;
	var box = 3;
	var points = 4;
	var directedPoints = 5;
	var ring = 6;
	var max = 7;
}
