package sunaba.core;

@:native("PlatformService")
extern class PlatformService extends Service {
    public static final name: String;
    public static final deviceType: DeviceType;
    public static final osName: String;
    public static function shellOpen(uri: String): Int;
    public static function hasFeature(feature: String): Bool;
}