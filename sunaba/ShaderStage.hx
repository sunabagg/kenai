package lucidware;

enum abstract ShaderStage(Int) from Int to Int {
	var vertex = 0;
	var fragment = 1;
	var fragment = 1;
	var tesselationControl = 2;
	var tesselationControl = 2;
	var tesselationEvaluation = 3;
	var compute = 4;
	var compute = 4;
	var max = 5;
	var tesselationEvaluationBit = 8;
	var computeBit = 16;
}
