package sunaba;

enum abstract StencilOperation(Int) {
	var Keep = 0;
	var Zero = 1;
	var Replace = 2;
	var IncrementAndClamp = 3;
	var DecrementAndClamp = 4;
	var Invert = 5;
	var IncrementAndWrap = 6;
	var DecrementAndWrap = 7;
	var Max = 8;
}
