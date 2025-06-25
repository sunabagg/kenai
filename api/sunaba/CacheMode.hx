package sunaba;

enum abstract CacheMode(Int) from Int to Int {
	var ignore = 0;
	var reuse = 1;
	var replace = 2;
	var ignoreDeep = 3;
	var replaceDeep = 4;
}
