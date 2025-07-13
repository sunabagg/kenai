//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/theme.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/state.hpp>
#include <string>
#include <vector>

#include "core/element.h"
#include "core/io/io_manager.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();
    public:
        App();
        ~App();

        std::vector<std::string> args;

        PackedStringArray getArgs() {
            PackedStringArray result;
            for(std::string arg : args) {
                result.append(arg.c_str());
            }
            return result;
        }
        void setArgs(PackedStringArray argsPsa) {
            std::vector<std::string> argsVec;
            for (size_t i = 0; i < argsPsa.size(); i++)
            {
                String arg = argsPsa[i];
                std::string argStr = arg.utf8().get_data();
                argsVec.push_back(argStr);
            }
            args = argsVec;
        }

        sol::state global_state;

        sunaba::core::io::IoManager* ioManager;

        void _ready() override;
        void _process(double delta) override;

        void initState(bool sandboxed = true);

        void loadAndExecuteSbx(const String &path);

        void start( const String &path );

        // Mobdebug support
        void initMobdebug();
        void startMobdebug(const String& host = "localhost", int port = 8172);
        void stopMobdebug();

        void setTheme(Ref<Theme> theme);
        
        // Lua file loading
        static int loadFileRequire(lua_State* L);

        void godot_libopen(const String& path, const String& uri = "") {
            this->libopen(path.utf8().get_data(), uri.utf8().get_data());
        }

        void libopen(const std::string& path, const std::string& uri);
    };

    void bindRuntime(sol::state& lua);

    class Runtime : public Element {
        private:
            App* app = nullptr;
            
        public:
            Runtime() {
                setApp(memnew(App));
                onInit();
            }

            Runtime(App* a) {
                setApp(a);
            }

            App* getApp() {
                return app;
            }

            void setApp(App* a) {
                app = a;
                setNode(a);
            }

            std::vector<std::string> getArgs() {
                return app->args;
            }

            void setArgs(std::vector<std::string> args) {
                app->args = args;
            }

            void initState(bool sandboxed = true) {
                app->initState(sandboxed);
            }

            void loadAndExecuteSbx(const std::string &path) {
                app->loadAndExecuteSbx(path.c_str());
            }

            void initMobdebug() {
                app->initMobdebug();
            }

            void startMobdebug(const std::string& host = "localhost", int port = 8172) {
                app->startMobdebug(host.c_str(), port);
            }

            void stopMobdebug() {
                app->stopMobdebug();
            }

            void libopen(const std::string& path, const std::string& uri) {
                app->libopen(path, uri);
            }
    };
}



#endif //APP_H
