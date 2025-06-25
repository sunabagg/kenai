package lucidware;

enum abstract EventType(Int) from Int to Int {
	var none = 0;
	var connect = 1;
	var disconnect = 2;
	var receive = 3;
	var error = -1;
}
