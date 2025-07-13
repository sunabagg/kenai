#ifndef MOON_CONSOLE_H
#define MOON_CONSOLE_H

#include "../element.h"
#include "io_manager.h"

using namespace godot;
using namespace sunaba::core::io;

namespace sunaba::core::io {

    class MoonConsole : public Node
    {
        GDCLASS(MoonConsole, Node)
        protected:
            static void _bind_methods();
        public:
            sol::state console;
            
            std::string currentDir;

            MoonConsole() {
                console.open_libraries( 
                    sol::lib::base,
                    sol::lib::coroutine,
                    sol::lib::math,
                    sol::lib::count,
                    sol::lib::string,
                    sol::lib::table
                );
            }
    };

}

#endif