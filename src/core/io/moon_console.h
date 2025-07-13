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
            static void _bind_methods() {}
        public:
            sol::state console;

            IoInterface* ioInterface;
            
            std::string currentDir;

            std::vector<std::string> logs;
            
            TypedDictionary<String, Color> logColors;

            std::vector<std::string> cmdNames;

            std::vector<sol::function> cmdFunctions;

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

                console["A"] = [this](sol::variadic_args args) {
                    std::vector<std::string> argsv;
                    for (const auto& arg: args) {
                        if (arg.is<std::string>()) {
                            if (arg.as<std::string>() != "") {
                                argsv.push_back(arg.as<std::string>());
                            }
                        }
                    }
                    return argsv;
                };

                console["cd"] = [this](std::string dir) {
                    if (ioInterface == nullptr) return;
                    if (ioInterface->directoryExists(currentDir + dir + "/")) {
                        dir = currentDir + dir + "/";
                    }
                    if (!String(dir.c_str()).ends_with("/")) {
                        dir = dir + "/";
                    }
                    if (!ioInterface->directoryExists(dir)) {
                        printErr(String("Error: invalid dir").utf8().get_data());
                    }
                    else {
                        currentDir = dir;
                    }
                };

                console["cat"] = [this](std::string path) {
                    std::string empty = "";
                    if (ioInterface == nullptr) return empty;
                    if (!ioInterface->fileExists(path)) return empty;
                    auto str = ioInterface->loadText(path);
                    print(str);
                    return str;
                };

                auto& cmdFunc = [this](std::string commandName, std::vector<std::string> args) {
                    this->cmd(commandName, args);
                };

                console["cmd"] = cmdFunc;
                console["$"] = cmdFunc;

                console["eval"] = [this](std::string code) {
                    int res = this->eval(code);
                    return res;
                };
                console["OK"] = Error::OK;
                console["FAILED"] = Error::FAILED;
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

            Error cmd(std::string commandName, std::vector<std::string> args) {
                if (ioInterface != nullptr) {
                    if (!String(commandName.c_str()).contains("://")) {
                        if (ioInterface->fileExists(currentDir + commandName)) {
                            commandName = currentDir + commandName;
                        }
                    }
                    if (ioInterface->fileExists(commandName)) {
                        console["__args__"] = args;
                        auto code = ioInterface->loadText(commandName);
                        return eval(code);
                    }
                }
                
                sol::function func;
                for (size_t i = 0; i < cmdNames.size(); i++)
                {
                    if (cmdNames[i] == commandName) {
                        func = cmdFunctions[i];
                    }
                }
                
                auto res = func(args);
                int errorcode = res.get<int>();
                return static_cast<Error>(errorcode);
            }

            Error eval(std::string code) {
                sol::protected_function_result result = console.safe_script(code);
                if (!result.valid()) {
                    sol::error err = result;
                    String errstr = String( "Error: " ) + err.what();
                    printErr(errstr.utf8().get_data());
                    return Error::FAILED;
                }
                else {
                    return Error::OK;
                }
            }
    };

}

#endif