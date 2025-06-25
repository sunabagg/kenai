package lucidware;

enum abstract SpacingType(Int) from Int to Int {
	var glyph = 0;
	var space = 1;
	var top = 2;
	var bottom = 3;
	var max = 4;
}
