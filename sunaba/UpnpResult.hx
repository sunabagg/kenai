package lucidware;

enum abstract UpnpResult(Int) from Int to Int {
	var success = 0;
	var notAuthorized = 1;
	var portMappingNotFound = 2;
	var inconsistentParameters = 3;
	var noSuchEntryInArray = 4;
	var actionFailed = 5;
	var srcIpWildcardNotPermitted = 6;
	var extPortWildcardNotPermitted = 7;
	var intPortWildcardNotPermitted = 8;
	var remoteHostMustBeWildcard = 9;
	var extPortMustBeWildcard = 10;
	var noPortMapsAvailable = 11;
	var conflictWithOtherMechanism = 12;
	var conflictWithOtherMapping = 13;
	var samePortValuesRequired = 14;
	var onlyPermanentLeaseSupported = 15;
	var invalidGateway = 16;
	var invalidPort = 17;
	var invalidProtocol = 18;
	var invalidDuration = 19;
	var invalidArgs = 20;
	var invalidResponse = 21;
	var invalidParam = 22;
	var httpError = 23;
	var socketError = 24;
	var memAllocError = 25;
	var noGateway = 26;
	var noDevices = 27;
	var unknownError = 28;
}
