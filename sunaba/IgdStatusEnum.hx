package sunaba;

enum abstract IgdStatusEnum(Int) {
	var Ok = 0;
	var HttpError = 1;
	var HttpEmpty = 2;
	var NoUrls = 3;
	var NoIgd = 4;
	var Disconnected = 5;
	var UnknownDevice = 6;
	var InvalidControl = 7;
	var MallocError = 8;
	var UnknownError = 9;
}
