package lucidfx;

enum abstract EnvironmentBG(Int) from Int to Int {
	var clearColor = 0;
	var color = 1;
	var sky = 2;
	var canvas = 3;
	var keep = 4;
	var cameraFeed = 5;
	var max = 6;
}
