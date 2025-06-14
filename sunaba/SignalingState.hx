package sunaba;

enum abstract SignalingState(Int) {
	var Stable = 0;
	var HaveLocalOffer = 1;
	var HaveRemoteOffer = 2;
	var HaveLocalPranswer = 3;
	var HaveRemotePranswer = 4;
	var Closed = 5;
}
