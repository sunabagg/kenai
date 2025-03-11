//
// Created by lucas on 1/31/2025.
//

#ifndef NH_OBJECT_H
#define NH_OBJECT_H

#include <lua.h>
#include <quickjs.h>

namespace sunaba::core
{
    //static void generateBaseObjectUsertype(lua_State* L);

    void registerBaseObject(JSContext* ctx);
    void jsBaseObjectFinalizer(JSRuntime* rt, JSValue val) {}
    JSValue jsBaseObjectConstructor(JSContext* ctx, JSValueConst newTarget,  int argc, JSValueConst* argv);

    class BaseObject {
    public:
        virtual void onNotification( int p_what ) {}

        void notification(const int p_notification, bool p_reversed = false);

        bool freed = false;

        static JSClassID baseObjectClassID;

        static const JSClassDef baseObjectJsClass;

        virtual void onFree() {}
        
        void free() { 
            this->onFree();
            freed = true;
        }

        virtual ~BaseObject() {
            if (!freed) {
                free();
            }
        }
    };
}

#endif //NH_OBJECT_H
