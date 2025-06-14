package sunaba;

enum abstract StretchModeEnum(Int) {
	var Scale = 0;
	var Tile = 1;
	var Keep = 2;
	var KeepCentered = 3;
	var KeepAspect = 4;
	var KeepAspectCentered = 5;
	var KeepAspectCovered = 6;
}
