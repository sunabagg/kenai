//
// Created by lucas on 1/31/2025.
//

#ifndef NH_OBJECT_H
#define NH_OBJECT_H

#include <lua.h>

namespace newhaven_core
{
    //static void generateBaseObjectUsertype(lua_State* L);

    class BaseObject {
    public:
        virtual void onFree() {}
        void free();
    };
}

#endif //NH_OBJECT_H
