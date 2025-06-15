package sunaba;

enum abstract EnvironmentModeEnum(Int) from Int to Int {
	var disabled = 0;
	var scene = 1;
	var customSky = 2;
	var customColor = 3;
}
