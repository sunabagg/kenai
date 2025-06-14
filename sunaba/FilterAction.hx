package sunaba;

enum abstract FilterAction(Int) {
	var Ignore = 0;
	var Pass = 1;
	var Stop = 2;
	var Blend = 3;
}
