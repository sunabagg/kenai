package sunaba;

enum abstract CellularDistanceFunctionEnum(Int) from Int to Int {
	var euclidean = 0;
	var euclideanSquared = 1;
	var manhattan = 2;
	var hybrid = 3;
}
