package lucidware;

enum abstract WindowFlags(Int) from Int to Int {
	var resizeDisabled = 0;
	var borderless = 1;
	var alwaysOnTop = 2;
	var transparent = 3;
	var noFocus = 4;
	var popup = 5;
	var extendToTitle = 6;
	var mousePassthrough = 7;
	var sharpCorners = 8;
	var excludeFromCapture = 9;
	var max = 10;
}
