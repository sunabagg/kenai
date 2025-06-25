package sunaba;

enum abstract ShadowQuality(Int) from Int to Int {
	var hard = 0;
	var softVeryLow = 1;
	var softLow = 2;
	var softMedium = 3;
	var softHigh = 4;
	var softUltra = 5;
	var max = 6;
}
