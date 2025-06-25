package lucidfx;

enum abstract OperationEnum(Int) from Int to Int {
	var union = 0;
	var intersection = 1;
	var subtraction = 2;
}
