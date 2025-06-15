package sunaba;

enum abstract SelectionMode(Int) from Int to Int {
	var none = 0;
	var shift = 1;
	var pointer = 2;
	var word = 3;
	var line = 4;
}
