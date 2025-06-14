package sunaba;

enum abstract TextOverrunFlag(Int) {
	var NoTrim = 0;
	var Trim = 1;
	var TrimWordOnly = 2;
	var AddEllipsis = 4;
	var EnforceEllipsis = 8;
	var JustificationAware = 16;
}
