package sunaba;

enum abstract CodeCompletionLocation(Int) {
	var Local = 0;
	var ParentMask = 256;
	var OtherUserCode = 512;
	var Other = 1024;
}
