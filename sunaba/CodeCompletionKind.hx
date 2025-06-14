package sunaba;

enum abstract CodeCompletionKind(Int) {
	var Class = 0;
	var Function = 1;
	var Signal = 2;
	var Variable = 3;
	var Member = 4;
	var Enum = 5;
	var Constant = 6;
	var NodePath = 7;
	var FilePath = 8;
	var PlainText = 9;
	var Max = 10;
}
