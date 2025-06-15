package sunaba;

enum abstract HandMotionRange(Int) from Int to Int {
	var unobstructed = 0;
	var conformToController = 1;
	var max = 2;
}
