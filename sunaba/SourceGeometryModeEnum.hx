package sunaba;

enum abstract SourceGeometryModeEnum(Int) from Int to Int {
	var rootNodeChildren = 0;
	var groupsWithChildren = 1;
	var groupsExplicit = 2;
	var max = 3;
}
