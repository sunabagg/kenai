package sunaba;

enum abstract HintEnum(Int) from Int to Int {
	var none = 0;
	var range = 1;
	var rangeStep = 2;
	var enum = 3;
	var max = 4;
}
