//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>

#include "core/scene_system.h"

using namespace godot;

namespace sunaba
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();

        sol::state global_state;
    public:
        App();
        ~App();

        void _ready() override;
        void start( const String &path );

        sunaba::core::Scene* createScene();
    };
}



#endif //APP_H
