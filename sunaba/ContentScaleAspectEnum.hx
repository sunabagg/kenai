package lucidware;

enum abstract ContentScaleAspectEnum(Int) from Int to Int {
	var ignore = 0;
	var keep = 1;
	var keepWidth = 2;
	var keepHeight = 3;
	var expand = 4;
}
