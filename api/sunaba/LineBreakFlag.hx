package sunaba;

enum abstract LineBreakFlag(Int) from Int to Int {
	var none = 0;
	var mandatory = 1;
	var wordBound = 2;
	var graphemeBound = 4;
	var adaptive = 8;
	var trimEdgeSpaces = 16;
	var trimIndent = 32;
}
