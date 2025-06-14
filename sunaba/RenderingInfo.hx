package sunaba;

enum abstract RenderingInfo(Int) {
	var TotalObjectsInFrame = 0;
	var TotalPrimitivesInFrame = 1;
	var TotalDrawCallsInFrame = 2;
	var TextureMemUsed = 3;
	var BufferMemUsed = 4;
	var VideoMemUsed = 5;
	var PipelineCompilationsCanvas = 6;
	var PipelineCompilationsMesh = 7;
	var PipelineCompilationsSurface = 8;
	var PipelineCompilationsDraw = 9;
	var PipelineCompilationsSpecialization = 10;
}
