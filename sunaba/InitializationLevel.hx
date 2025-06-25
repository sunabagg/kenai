package lucidware;

enum abstract InitializationLevel(Int) from Int to Int {
	var core = 0;
	var servers = 1;
	var scene = 2;
	var editor = 3;
}
