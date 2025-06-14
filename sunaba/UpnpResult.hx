package sunaba;

enum abstract UpnpResult(Int) {
	var Success = 0;
	var NotAuthorized = 1;
	var PortMappingNotFound = 2;
	var InconsistentParameters = 3;
	var NoSuchEntryInArray = 4;
	var ActionFailed = 5;
	var SrcIPWildcardNotPermitted = 6;
	var ExtPortWildcardNotPermitted = 7;
	var IntPortWildcardNotPermitted = 8;
	var RemoteHostMustBeWildcard = 9;
	var ExtPortMustBeWildcard = 10;
	var NoPortMapsAvailable = 11;
	var ConflictWithOtherMechanism = 12;
	var ConflictWithOtherMapping = 13;
	var SamePortValuesRequired = 14;
	var OnlyPermanentLeaseSupported = 15;
	var InvalidGateway = 16;
	var InvalidPort = 17;
	var InvalidProtocol = 18;
	var InvalidDuration = 19;
	var InvalidArgs = 20;
	var InvalidResponse = 21;
	var InvalidParam = 22;
	var HttpError = 23;
	var SocketError = 24;
	var MemAllocError = 25;
	var NoGateway = 26;
	var NoDevices = 27;
	var UnknownError = 28;
}
