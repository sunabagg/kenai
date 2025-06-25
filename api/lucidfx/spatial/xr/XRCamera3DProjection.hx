package lucidfx..spatial.xr;

enum abstract XRCamera3DProjection(Int) from Int to Int {
	var perspective = 0;
	var orthogonal = 1;
	var frustum = 2;
}
