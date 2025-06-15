package sunaba;

enum abstract ToneMapper(Int) from Int to Int {
	var linear = 0;
	var reinhardt = 1;
	var filmic = 2;
	var aces = 3;
	var agx = 4;
}
