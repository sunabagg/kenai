package lucidfx;

enum abstract SignalingState(Int) from Int to Int {
	var stable = 0;
	var haveLocalOffer = 1;
	var haveRemoteOffer = 2;
	var haveLocalPranswer = 3;
	var haveRemotePranswer = 4;
	var closed = 5;
}
