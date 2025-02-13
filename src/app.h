//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>
#include <v8.h>

#include "core/scene_system.h"

using namespace godot;

namespace newhaven
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();

        sol::state global_state;
        
        v8::Isolate* isolate;

        v8::Platform* platform;
    public:
        App();
        ~App();

        void init_v8();

        void _ready() override;
        void start();

        newhaven_core::Scene* createScene();
    };
}



#endif //APP_H
