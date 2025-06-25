package lucidfx;

enum abstract GroupCallFlags(Int) from Int to Int {
	var default = 0;
	var reverse = 1;
	var deferred = 2;
	var unique = 4;
}
