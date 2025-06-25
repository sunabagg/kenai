package lucidfx..spatial.xr;

enum abstract OpenXRCompositionLayerRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
