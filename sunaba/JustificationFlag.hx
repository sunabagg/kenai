package sunaba;

enum abstract JustificationFlag(Int) {
	var None = 0;
	var Kashida = 1;
	var WordBound = 2;
	var TrimEdgeSpaces = 4;
	var AfterLastTab = 8;
	var ConstrainEllipsis = 16;
	var SkipLastLine = 32;
	var SkipLastLineWithVisibleChars = 64;
	var DoNotSkipSingleLine = 128;
}
