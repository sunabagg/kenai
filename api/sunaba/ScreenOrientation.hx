package sunaba;

enum abstract ScreenOrientation(Int) from Int to Int {
	var landscape = 0;
	var portrait = 1;
	var reverseLandscape = 2;
	var reversePortrait = 3;
	var sensorLandscape = 4;
	var sensorPortrait = 5;
	var sensor = 6;
}
