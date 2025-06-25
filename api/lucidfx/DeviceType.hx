package lucidfx;

enum abstract DeviceType(Int) from Int to Int {
	var other = 0;
	var integratedGpu = 1;
	var discreteGpu = 2;
	var virtualGpu = 3;
	var cpu = 4;
	var max = 5;
}
