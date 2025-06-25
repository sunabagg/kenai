package sunaba;

enum abstract PlatformOnLeaveEnum(Int) from Int to Int {
	var addVelocity = 0;
	var addUpwardVelocity = 1;
	var doNothing = 2;
}
