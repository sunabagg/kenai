#ifndef SERVICE_H
#define SERVICE_H

#include <sol/sol.hpp>

namespace sunaba::core {
    void bindService(sol::state& lua);

    class ServiceInstance;

    class Service {  
        static ServiceInstance* placeholderGetInstance() {
            return nullptr;
        }
    };

    class ServiceInstance {
        public:
            ServiceInstance() {}
            ~ServiceInstance() {}
    };
}

#endif