package sunaba;

enum abstract Result(Int) {
	var Success = 0;
	var ChunkedBodySizeMismatch = 1;
	var CantConnect = 2;
	var CantResolve = 3;
	var ConnectionError = 4;
	var TlsHandshakeError = 5;
	var NoResponse = 6;
	var BodySizeLimitExceeded = 7;
	var BodyDecompressFailed = 8;
	var RequestFailed = 9;
	var DownloadFileCantOpen = 10;
	var DownloadFileWriteError = 11;
	var RedirectLimitReached = 12;
	var Timeout = 13;
}
