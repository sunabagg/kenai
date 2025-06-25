package lucidware;

enum abstract TransformFlag(Int) from Int to Int {
	var position = 1;
	var rotation = 2;
	var scale = 4;
	var all = 7;
}
