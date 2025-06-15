package sunaba;

enum abstract HandTrackingSourceEnum(Int) from Int to Int {
	var unknown = 0;
	var unobstructed = 1;
	var controller = 2;
	var notTracked = 3;
	var max = 4;
}
