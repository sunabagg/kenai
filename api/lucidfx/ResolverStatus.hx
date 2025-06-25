package lucidfx;

enum abstract ResolverStatus(Int) from Int to Int {
	var none = 0;
	var waiting = 1;
	var done = 2;
	var error = 3;
}
