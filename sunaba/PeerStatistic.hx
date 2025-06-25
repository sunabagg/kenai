package lucidware;

enum abstract PeerStatistic(Int) from Int to Int {
	var packetLoss = 0;
	var packetLossVariance = 1;
	var packetLossEpoch = 2;
	var roundTripTime = 3;
	var roundTripTimeVariance = 4;
	var lastRoundTripTime = 5;
	var lastRoundTripTimeVariance = 6;
	var packetThrottle = 7;
	var packetThrottleLimit = 8;
	var packetThrottleCounter = 9;
	var packetThrottleEpoch = 10;
	var packetThrottleAcceleration = 11;
	var packetThrottleDeceleration = 12;
	var packetThrottleInterval = 13;
}
