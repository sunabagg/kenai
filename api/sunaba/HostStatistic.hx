package sunaba;

enum abstract HostStatistic(Int) from Int to Int {
	var sentData = 0;
	var sentPackets = 1;
	var receivedData = 2;
	var receivedPackets = 3;
}
