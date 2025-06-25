package lucidware;

enum abstract LightModeEnum(Int) from Int to Int {
	var normal = 0;
	var unshaded = 1;
	var lightOnly = 2;
}
