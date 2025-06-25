package lucidware..spatial.xr;

enum abstract XRCamera3DDopplerTracking(Int) from Int to Int {
	var disabled = 0;
	var idleStep = 1;
	var physicsStep = 2;
}
