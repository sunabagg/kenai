package lucidfx;

enum abstract ConnectFlags(Int) from Int to Int {
	var deferred = 1;
	var persist = 2;
	var oneShot = 4;
	var referenceCounted = 8;
}
