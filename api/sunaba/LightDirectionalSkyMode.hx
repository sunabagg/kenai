package sunaba;

enum abstract LightDirectionalSkyMode(Int) from Int to Int {
	var lightAndSky = 0;
	var lightOnly = 1;
	var skyOnly = 2;
}
