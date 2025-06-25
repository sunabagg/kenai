package sunaba..spatial.navigation;

enum abstract NavigationRegion3DRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
