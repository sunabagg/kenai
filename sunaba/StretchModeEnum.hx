package lucidware;

enum abstract StretchModeEnum(Int) from Int to Int {
	var scale = 0;
	var tile = 1;
	var keep = 2;
	var keepCentered = 3;
	var keepAspect = 4;
	var keepAspectCentered = 5;
	var keepAspectCovered = 6;
}
