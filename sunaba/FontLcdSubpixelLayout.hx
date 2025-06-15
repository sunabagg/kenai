package sunaba;

enum abstract FontLcdSubpixelLayout(Int) from Int to Int {
	var none = 0;
	var hrgb = 1;
	var hbgr = 2;
	var vrgb = 3;
	var vbgr = 4;
	var max = 5;
}
