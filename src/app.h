//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>

#include "core/scene_system.h"
#include "core/io/io_manager.h"
#include "core/sol_gdstr.h"

using namespace godot;

namespace sunaba
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();
    public:
        App();
        ~App();

        sol::state global_state;

        sunaba::core::io::IoManager* ioManager;

        void _ready() override;
        void _process(double delta) override;
        void start( const String &path );

        sunaba::core::Scene* createScene();
    };
}



#endif //APP_H
