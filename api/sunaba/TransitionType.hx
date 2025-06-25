package sunaba;

enum abstract TransitionType(Int) from Int to Int {
	var linear = 0;
	var sine = 1;
	var quint = 2;
	var quart = 3;
	var quad = 4;
	var expo = 5;
	var elastic = 6;
	var cubic = 7;
	var circ = 8;
	var bounce = 9;
	var back = 10;
	var spring = 11;
}
