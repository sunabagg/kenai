package sunaba;

enum abstract HandTrackingSourceEnum(Int) {
	var Unknown = 0;
	var Unobstructed = 1;
	var Controller = 2;
	var NotTracked = 3;
	var Max = 4;
}
