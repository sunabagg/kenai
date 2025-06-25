package lucidware..spatial;

enum abstract StandardMaterial3DDepthDrawMode(Int) from Int to Int {
	var opaqueOnly = 0;
	var always = 1;
	var disabled = 2;
}
