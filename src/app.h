//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>

#include "core/scene_system.h"
#include "core/scene_node.h"

using namespace godot;

namespace newhaven
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();

        sol::state global_state;
    public:
        App();
        ~App();

        List<newhaven_core::SceneNode*> scenes;

        void _ready() override;
        void start();

        newhaven_core::Scene* createScene();
    };
}



#endif //APP_H
