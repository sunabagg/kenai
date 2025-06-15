package sunaba;

enum abstract RenderingInfo(Int) from Int to Int {
	var totalObjectsInFrame = 0;
	var totalPrimitivesInFrame = 1;
	var totalDrawCallsInFrame = 2;
	var textureMemUsed = 3;
	var bufferMemUsed = 4;
	var videoMemUsed = 5;
	var pipelineCompilationsCanvas = 6;
	var pipelineCompilationsMesh = 7;
	var pipelineCompilationsSurface = 8;
	var pipelineCompilationsDraw = 9;
	var pipelineCompilationsSpecialization = 10;
}
