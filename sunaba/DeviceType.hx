package sunaba;

enum abstract DeviceType(Int) {
	var Other = 0;
	var IntegratedGpu = 1;
	var DiscreteGpu = 2;
	var VirtualGpu = 3;
	var Cpu = 4;
	var Max = 5;
}
