package sunaba;

enum abstract JustificationFlag(Int) from Int to Int {
	var none = 0;
	var kashida = 1;
	var wordBound = 2;
	var trimEdgeSpaces = 4;
	var afterLastTab = 8;
	var constrainEllipsis = 16;
	var skipLastLine = 32;
	var skipLastLineWithVisibleChars = 64;
	var doNotSkipSingleLine = 128;
}
