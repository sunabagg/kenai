package sunaba;

enum abstract PrecisionEnum(Int) from Int to Int {
	var none = 0;
	var coarse = 1;
	var fine = 2;
	var max = 3;
}
