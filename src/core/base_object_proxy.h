#ifndef BASE_OBJECT_PROXY_H
#define BASE_OBJECT_PROXY_H

#include <godot_cpp/classes/object.hpp>
#include "base_object.h"

using namespace godot;

namespace lucidware::core {
    class BaseObjectProxy : public Object {
        GDCLASS(BaseObjectProxy, Object);
    protected:
        static void _bind_methods() {
        }
    public:
        BaseObject* base_object = nullptr;

        BaseObjectProxy() {
        }
    };
}

#endif // BASE_OBJECT_PROXY_H