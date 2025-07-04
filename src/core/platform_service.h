#ifndef PLATFORM_SERVICE_H
#define PLATFORM_SERVICE_H

#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#include "service.h"
#include <Version.h>

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
                if (getOS()->has_feature("mobile")) {
                    return 1;
                }
                else if (getOS()->get_name() == "Windows" || getOS()->get_name() == "Linux" || getOS()->get_name() == "macOS") {
                    return 0;
                }
                else if (getOS()->get_name() == "Android") {
                    return 1;
                }
                else if (getOS()->get_name() == "iOS") {
                    return 1;
                }
                else if (getOS()->get_name() == "HTML5") {
                    return 2;
                }
                else if (getOS()->get_name() == "Web") {
                    return 2;
                }
                else if (getOS()->get_name() == "visionOS") {
                    return 3;
                }
                else {
                    return -1; // Unknown or unsupported device type
                }
            }

    };
}
#endif // PLATFORM_SERVICE_H