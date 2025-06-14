package sunaba;

enum abstract LoadStatus(Int) {
	var Ok = 0;
	var Failed = 1;
	var AlreadyLoaded = 2;
	var NotLoaded = 3;
	var NeedsRestart = 4;
}
