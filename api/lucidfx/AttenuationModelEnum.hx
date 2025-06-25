package lucidfx;

enum abstract AttenuationModelEnum(Int) from Int to Int {
	var inverseDistance = 0;
	var inverseSquareDistance = 1;
	var logarithmic = 2;
	var disabled = 3;
}
