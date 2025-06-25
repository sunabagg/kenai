package lucidware;

enum abstract ParsedGeometryType(Int) from Int to Int {
	var meshInstances = 0;
	var staticColliders = 1;
	var both = 2;
	var max = 3;
}
