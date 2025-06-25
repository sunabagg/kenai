package lucidware;

enum abstract DiffuseModeEnum(Int) from Int to Int {
	var burley = 0;
	var lambert = 1;
	var lambertWrap = 2;
	var toon = 3;
}
