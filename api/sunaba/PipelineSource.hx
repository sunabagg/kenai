package sunaba;

enum abstract PipelineSource(Int) from Int to Int {
	var canvas = 0;
	var mesh = 1;
	var surface = 2;
	var draw = 3;
	var specialization = 4;
	var max = 5;
}
