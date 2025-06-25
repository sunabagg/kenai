package lucidware;

enum abstract LoadStatus(Int) from Int to Int {
	var ok = 0;
	var failed = 1;
	var alreadyLoaded = 2;
	var notLoaded = 3;
	var needsRestart = 4;
}
