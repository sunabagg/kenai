package lucidware;

enum abstract ImageUpdateMask(Int) from Int to Int {
	var texture = 1;
	var size = 2;
	var color = 4;
	var alignment = 8;
	var region = 16;
	var pad = 32;
	var tooltip = 64;
	var widthInPercent = 128;
}
