package sunaba;

enum abstract PeerStatistic(Int) {
	var PacketLoss = 0;
	var PacketLossVariance = 1;
	var PacketLossEpoch = 2;
	var RoundTripTime = 3;
	var RoundTripTimeVariance = 4;
	var LastRoundTripTime = 5;
	var LastRoundTripTimeVariance = 6;
	var PacketThrottle = 7;
	var PacketThrottleLimit = 8;
	var PacketThrottleCounter = 9;
	var PacketThrottleEpoch = 10;
	var PacketThrottleAcceleration = 11;
	var PacketThrottleDeceleration = 12;
	var PacketThrottleInterval = 13;
}
