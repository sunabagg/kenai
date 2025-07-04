#ifndef PLATFORM_SERVICE_H
#define PLATFORM_SERVICE_H

#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#include "service.h"
#include <Version.h>

#define DEVICE_TYPE_DESKTOP 0
#define DEVICE_TYPE_MOBILE 1
#define DEVICE_TYPE_WEB 2
#define DEVICE_TYPE_XR 3
#define DEVICE_TYPE_UNKNOWN -1

using namespace godot;

namespace sunaba::core {
    void bindPlatformService(sol::state& lua);

    class PlatformService : public Service {
        private:
            static OS* osSingleton;

            static std::string platformName;

        public:
            static OS* getOS() {
                if (osSingleton == nullptr) {
                    osSingleton = OS::get_singleton();
                }
                return osSingleton;
            }

            static const std::string& getPlatformName() {
                return platformName;
            }

            static const int getDeviceType() {
                if (getOS()->get_name() == "Windows" || getOS()->get_name() == "Linux" || getOS()->get_name() == "macOS") {
                    return DEVICE_TYPE_DESKTOP;
                }
                else if (getOS()->get_name() == "Android") {
                    return DEVICE_TYPE_MOBILE;
                }
                else if (getOS()->get_name() == "iOS") {
                    return DEVICE_TYPE_MOBILE;
                }
                else if (getOS()->get_name() == "HTML5") {
                    return DEVICE_TYPE_WEB;
                }
                else if (getOS()->get_name() == "Web") {
                    return DEVICE_TYPE_WEB;
                }
                else if (getOS()->get_name() == "visionOS") {
                    return DEVICE_TYPE_XR;
                }
                    
                return DEVICE_TYPE_UNKNOWN; // Unknown or unsupported device type
            }

            static const std::string getOSName() {
                return getOS()->get_name().utf8().get_data();
            }

    };
}
#endif // PLATFORM_SERVICE_H