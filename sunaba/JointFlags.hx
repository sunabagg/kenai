package lucidware;

enum abstract JointFlags(Int) from Int to Int {
	var orientationValid = 1;
	var orientationTracked = 2;
	var positionValid = 4;
	var positionTracked = 8;
}
