package lucidfx;

enum abstract Method(Int) from Int to Int {
	var get = 0;
	var head = 1;
	var post = 2;
	var put = 3;
	var delete = 4;
	var options = 5;
	var trace = 6;
	var connect = 7;
	var patch = 8;
	var max = 9;
}
