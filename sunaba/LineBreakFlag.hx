package sunaba;

enum abstract LineBreakFlag(Int) {
	var None = 0;
	var Mandatory = 1;
	var WordBound = 2;
	var GraphemeBound = 4;
	var Adaptive = 8;
	var TrimEdgeSpaces = 16;
	var TrimIndent = 32;
}
