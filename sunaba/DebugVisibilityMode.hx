package lucidware;

enum abstract DebugVisibilityMode(Int) from Int to Int {
	var default = 0;
	var forceShow = 1;
	var forceHide = 2;
}
