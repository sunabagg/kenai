package lucidfx;

enum abstract godot_variant_call_error_error(Int) from Int to Int {
	var godotCallErrorCallOk = 0;
	var godotCallErrorCallErrorInvalidMethod = 1;
	var godotCallErrorCallErrorInvalidArgument = 2;
	var godotCallErrorCallErrorTooManyArguments = 3;
	var godotCallErrorCallErrorTooFewArguments = 4;
	var godotCallErrorCallErrorInstanceIsNull = 5;
	var godotCallErrorCallErrorMethodNotConst = 6;
}
