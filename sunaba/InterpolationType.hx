package sunaba;

enum abstract InterpolationType(Int) from Int to Int {
	var nearest = 0;
	var linear = 1;
	var cubic = 2;
	var linearAngle = 3;
	var cubicAngle = 4;
}
