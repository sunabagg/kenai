#ifndef IO_INDEX_H
#define IO_INDEX_H

#include "io_manager.h"
#include <sol/sol.hpp>
#include <map>
namespace lucidfx::core::io {
    class IoIndex {
    private:
        static std::map<sol::state_view, IoManager*> ioManagers;

    public:
        static IoManager* getIoManager(sol::state_view lua) {
            auto it = ioManagers.find(lua);
            if (it != ioManagers.end()) {
                return it->second;
            }
            return nullptr;
        }

        static void bindIoManger(sol::state_view& lua, IoManager* ioManager) {
            ioManagers[lua] = ioManager;
        }

        static void unbindIoManager(sol::state_view& lua) {
            ioManagers.erase(lua);
        }
    };
}

#endif //IO_INDEX_H