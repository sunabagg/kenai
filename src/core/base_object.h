//
// Created by lucas on 1/31/2025.
//

#ifndef NH_OBJECT_H
#define NH_OBJECT_H

#include <lua.h>

namespace sunaba::core
{
    //static void generateBaseObjectUsertype(lua_State* L);

    // A base class for all objects in the engine. This class is used to store a reference to the object in Lua,
    // and to make sure that the object is not freed while it is still being used.
    class BaseObject {
    public:
        virtual void onNotification( int p_what ) {}

        void notification(const int p_notification, bool p_reversed = false);

        bool freed = false;

        virtual void onFree() {}
        
        void free() { 
            if (!freed) {
                delete this;
            }
        }

        virtual ~BaseObject() {
            this->onFree();
            freed = true;
        }
    };

    // A reference to a native object. This is used to store a reference to a native object in Lua,
    // and to make sure that the object is not freed while it is still being used.
    template<typename T>
    class NativeReference {
    public:
        T* ptr = nullptr;

        NativeReference() : ptr(new T()) {}

        NativeReference(T* p_ptr) : ptr(p_ptr) {}

        ~NativeReference() {
            if (ptr != nullptr) {
                ptr = nullptr;
            }
        }

        T* operator->() {
            return ptr;
        }

        T& operator*() {
            return *ptr;
        }

        bool isNull() {
            return ptr == nullptr;
        }
    };

    class BaseReference : public NativeReference<BaseObject> { 
    public:
        using NativeReference<BaseObject>::NativeReference;
    };
}

#endif //NH_OBJECT_H
