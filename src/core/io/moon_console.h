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

            IoInterface* ioInterface;
            
            std::string currentDir;

            std::vector<std::string> logs;
            
            TypedDictionary<String, Color> logColors;

            MoonConsole() {
                console.open_libraries( 
                    sol::lib::base,
                    sol::lib::coroutine,
                    sol::lib::math,
                    sol::lib::count,
                    sol::lib::string,
                    sol::lib::table
                );

                console["print"] = [this](sol::variadic_args args) {
                    String log;
                    for (const auto& arg: args) {
                        if (arg.is<std::string>()) {
                            if (!log.is_empty()) {
                                log += " ";
                            }
                            log += arg.as<std::string>().c_str();
                        }
                    }
                    print(log.utf8().get_data());
                };

                console["printErr"] = [this](sol::variadic_args args) {
                    String log;
                    for (const auto& arg: args) {
                        if (arg.is<std::string>()) {
                            if (!log.is_empty()) {
                                log += " ";
                            }
                            log += arg.as<std::string>().c_str();
                        }
                    }
                    printErr(log.utf8().get_data());
                };

                console["printColor"] = [this](std::string log, std::string clrstr) {
                    printColor(log, clrstr);
                };

                console["cd"] = [this](std::string dir) {
                    if (!ioInterface->directoryExists(dir)) {
                        printErr(String("ERROR: invalid dir").utf8().get_data());
                    }
                    else {
                        currentDir = dir;
                    }
                };
            }

            Color getLogColor(std::string log) {
                return logColors[log.c_str()];
            }

            void print(std::string log) {
                logs.push_back(log);
                logColors[log.c_str()] = Color("#ffffff");
            }

            void printErr(std::string error) {
                logs.push_back(error);
                logColors[error.c_str()] = Color("#ff5733");
            }

            void printColor(std::string log, std::string clrstr) {
                Color& color = Color(clrstr.c_str());
                logs.push_back(log);
                logColors[log.c_str()] = color;
            }
    };

}

#endif