package sunaba;

enum abstract CullModeEnum(Int) from Int to Int {
	var disabled = 0;
	var clockwise = 1;
	var counterClockwise = 2;
}
