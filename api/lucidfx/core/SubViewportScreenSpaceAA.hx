package lucidfx..core;

enum abstract SubViewportScreenSpaceAA(Int) from Int to Int {
	var disabled = 0;
	var fxaa = 1;
	var max = 2;
}
