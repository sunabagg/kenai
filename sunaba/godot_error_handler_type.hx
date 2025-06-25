package lucidfx;

enum abstract godot_error_handler_type(Int) from Int to Int {
	var errHandlerError = 0;
	var errHandlerWarning = 1;
	var errHandlerScript = 2;
	var errHandlerShader = 3;
}
