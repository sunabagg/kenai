package sunaba;

enum abstract FilterAction(Int) from Int to Int {
	var ignore = 0;
	var pass = 1;
	var stop = 2;
	var blend = 3;
}
