package sunaba;

enum abstract DiagonalModeEnum(Int) {
	var Always = 0;
	var Never = 1;
	var AtLeastOneWalkable = 2;
	var OnlyIfNoObstacles = 3;
	var Max = 4;
}
