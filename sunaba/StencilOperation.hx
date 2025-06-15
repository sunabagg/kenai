package sunaba;

enum abstract StencilOperation(Int) from Int to Int {
	var keep = 0;
	var zero = 1;
	var replace = 2;
	var incrementAndClamp = 3;
	var decrementAndClamp = 4;
	var invert = 5;
	var incrementAndWrap = 6;
	var decrementAndWrap = 7;
	var max = 8;
}
