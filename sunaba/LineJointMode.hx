package lucidware;

enum abstract LineJointMode(Int) from Int to Int {
	var sharp = 0;
	var bevel = 1;
	var round = 2;
}
