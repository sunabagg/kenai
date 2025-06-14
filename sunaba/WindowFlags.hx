package sunaba;

enum abstract WindowFlags(Int) {
	var ResizeDisabled = 0;
	var Borderless = 1;
	var AlwaysOnTop = 2;
	var Transparent = 3;
	var NoFocus = 4;
	var Popup = 5;
	var ExtendToTitle = 6;
	var MousePassthrough = 7;
	var SharpCorners = 8;
	var ExcludeFromCapture = 9;
	var Max = 10;
}
