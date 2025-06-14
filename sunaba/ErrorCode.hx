package sunaba;

enum abstract ErrorCode(Int) {
	var ParseError = -32700;
	var InternalError = -32603;
	var InvalidParams = -32602;
	var MethodNotFound = -32601;
	var InvalidRequest = -32600;
}
