package sunaba;

enum abstract ConnectFlags(Int) {
	var Deferred = 1;
	var Persist = 2;
	var OneShot = 4;
	var ReferenceCounted = 8;
}
