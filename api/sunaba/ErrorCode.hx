package sunaba;

enum abstract ErrorCode(Int) from Int to Int {
	var parseError = -32700;
	var internalError = -32603;
	var invalidParams = -32602;
	var methodNotFound = -32601;
	var invalidRequest = -32600;
}
