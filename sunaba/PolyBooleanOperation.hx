package lucidfx;

enum abstract PolyBooleanOperation(Int) from Int to Int {
	var union = 0;
	var difference = 1;
	var intersection = 2;
	var xor = 3;
}
