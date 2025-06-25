package lucidware..spatial.xr;

enum abstract OpenXRHandRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
