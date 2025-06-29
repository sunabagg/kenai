#ifndef SERVICE_H
#define SERVICE_H

#include <sol/sol.hpp>

namespace sunaba::core {
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