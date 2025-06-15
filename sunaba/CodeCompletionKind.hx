package sunaba;

enum abstract CodeCompletionKind(Int) from Int to Int {
	var class = 0;
	var function = 1;
	var signal = 2;
	var variable = 3;
	var member = 4;
	var enum = 5;
	var constant = 6;
	var nodePath = 7;
	var filePath = 8;
	var plainText = 9;
	var max = 10;
}
