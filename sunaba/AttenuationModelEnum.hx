package sunaba;

enum abstract AttenuationModelEnum(Int) {
	var InverseDistance = 0;
	var InverseSquareDistance = 1;
	var Logarithmic = 2;
	var Disabled = 3;
}
