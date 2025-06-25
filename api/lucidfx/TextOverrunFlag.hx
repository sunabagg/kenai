package lucidfx;

enum abstract TextOverrunFlag(Int) from Int to Int {
	var noTrim = 0;
	var trim = 1;
	var trimWordOnly = 2;
	var addEllipsis = 4;
	var enforceEllipsis = 8;
	var justificationAware = 16;
}
