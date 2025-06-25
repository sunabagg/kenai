package sunaba;

enum abstract FractalTypeEnum(Int) from Int to Int {
	var none = 0;
	var fbm = 1;
	var ridged = 2;
	var pingPong = 3;
}
