package sunaba;

enum abstract FindMode(Int) from Int to Int {
	var nearest = 0;
	var approx = 1;
	var exact = 2;
}
