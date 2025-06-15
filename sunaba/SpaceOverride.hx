package sunaba;

enum abstract SpaceOverride(Int) from Int to Int {
	var disabled = 0;
	var combine = 1;
	var combineReplace = 2;
	var replace = 3;
	var replaceCombine = 4;
}
