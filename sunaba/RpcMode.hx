package lucidware;

enum abstract RpcMode(Int) from Int to Int {
	var disabled = 0;
	var anyPeer = 1;
	var authority = 2;
}
