#ifndef MOON_CONSOLE_H
#define MOON_CONSOLE_H

#include <godot_cpp/variant/typed_dictionary.hpp>

#include "../element.h"
#include "io_interface.h"

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

            IoInterface ioInterface;
            
            std::string currentDir;

            std::vector<std::string> logs;
            
            TypedDictionary<int, Color> logColors;

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

            Color getLogColor(std::string log) {
                auto index = 0;
                for (size_t i = 0; i < logs.size(); i++)
                {
                    if (logs[i] == log) {
                        index = i;
                        break;
                    }
                }
                
                return logColors[index];
            }
    };

}

#endif