package lucidware;

enum abstract VisibilityUpdateModeEnum(Int) from Int to Int {
	var idle = 0;
	var physics = 1;
	var none = 2;
}
