package sunaba;

enum abstract CacheMode(Int) {
	var Ignore = 0;
	var Reuse = 1;
	var Replace = 2;
	var IgnoreDeep = 3;
	var ReplaceDeep = 4;
}
