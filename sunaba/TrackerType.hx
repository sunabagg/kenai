package sunaba;

enum abstract TrackerType(Int) {
	var Head = 1;
	var Controller = 2;
	var Basestation = 4;
	var Anchor = 8;
	var Hand = 16;
	var Body = 32;
	var Face = 64;
	var AnyKnown = 127;
	var Unknown = 128;
	var Any = 255;
}
