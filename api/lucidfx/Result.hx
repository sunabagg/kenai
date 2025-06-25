package lucidfx;

enum abstract Result(Int) from Int to Int {
	var success = 0;
	var chunkedBodySizeMismatch = 1;
	var cantConnect = 2;
	var cantResolve = 3;
	var connectionError = 4;
	var tlsHandshakeError = 5;
	var noResponse = 6;
	var bodySizeLimitExceeded = 7;
	var bodyDecompressFailed = 8;
	var requestFailed = 9;
	var downloadFileCantOpen = 10;
	var downloadFileWriteError = 11;
	var redirectLimitReached = 12;
	var timeout = 13;
}
