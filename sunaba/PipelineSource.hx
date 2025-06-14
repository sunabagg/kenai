package sunaba;

enum abstract PipelineSource(Int) {
	var Canvas = 0;
	var Mesh = 1;
	var Surface = 2;
	var Draw = 3;
	var Specialization = 4;
	var Max = 5;
}
