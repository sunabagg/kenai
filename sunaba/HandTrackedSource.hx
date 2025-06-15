package sunaba;

enum abstract HandTrackedSource(Int) from Int to Int {
	var unknown = 0;
	var unobstructed = 1;
	var controller = 2;
	var max = 3;
}
