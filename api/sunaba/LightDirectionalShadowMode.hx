package sunaba;

enum abstract LightDirectionalShadowMode(Int) from Int to Int {
	var orthogonal = 0;
	var parallel2Splits = 1;
	var parallel4Splits = 2;
}
