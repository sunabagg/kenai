package lucidware;

enum abstract EnvironmentToneMapper(Int) from Int to Int {
	var linear = 0;
	var reinhard = 1;
	var filmic = 2;
	var aces = 3;
	var agx = 4;
}
