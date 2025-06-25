package lucidfx;

enum abstract DiagonalModeEnum(Int) from Int to Int {
	var always = 0;
	var never = 1;
	var atLeastOneWalkable = 2;
	var onlyIfNoObstacles = 3;
	var max = 4;
}
