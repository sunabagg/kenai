package lucidware;

enum abstract HashType(Int) from Int to Int {
	var md5 = 0;
	var sha1 = 1;
	var sha256 = 2;
}
