package sunaba;

enum abstract SelectionMode(Int) {
	var None = 0;
	var Shift = 1;
	var Pointer = 2;
	var Word = 3;
	var Line = 4;
}
