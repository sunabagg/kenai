package lucidware;

enum abstract InternalMode(Int) from Int to Int {
	var disabled = 0;
	var front = 1;
	var back = 2;
}
