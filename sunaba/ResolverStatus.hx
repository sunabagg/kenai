package sunaba;

enum abstract ResolverStatus(Int) {
	var None = 0;
	var Waiting = 1;
	var Done = 2;
	var Error = 3;
}
