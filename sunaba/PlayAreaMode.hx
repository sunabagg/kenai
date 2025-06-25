package lucidware;

enum abstract PlayAreaMode(Int) from Int to Int {
	var unknown = 0;
	var area3Dof = 1;
	var sitting = 2;
	var roomscale = 3;
	var stage = 4;
}
