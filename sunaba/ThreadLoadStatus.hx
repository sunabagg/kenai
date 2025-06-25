package lucidware;

enum abstract ThreadLoadStatus(Int) from Int to Int {
	var invalidResource = 0;
	var inProgress = 1;
	var failed = 2;
	var loaded = 3;
}
