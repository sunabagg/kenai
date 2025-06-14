package sunaba;

enum abstract ImageUpdateMask(Int) {
	var Texture = 1;
	var Size = 2;
	var Color = 4;
	var Alignment = 8;
	var Region = 16;
	var Pad = 32;
	var Tooltip = 64;
	var WidthInPercent = 128;
}
