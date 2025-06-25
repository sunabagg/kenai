package lucidfx;

enum abstract SubpixelPositioning(Int) from Int to Int {
	var disabled = 0;
	var auto = 1;
	var oneHalf = 2;
	var oneQuarter = 3;
	var oneQuarterMaxSize = 16;
	var oneHalfMaxSize = 20;
}
