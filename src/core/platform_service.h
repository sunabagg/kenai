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

    };
}
#endif // PLATFORM_SERVICE_H