package lucidware;

enum abstract ProcessModeEnum(Int) from Int to Int {
	var automatic = 0;
	var quality = 1;
	var incremental = 2;
	var realtime = 3;
}
