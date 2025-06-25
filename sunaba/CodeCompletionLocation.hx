package lucidware;

enum abstract CodeCompletionLocation(Int) from Int to Int {
	var local = 0;
	var parentMask = 256;
	var otherUserCode = 512;
	var other = 1024;
}
