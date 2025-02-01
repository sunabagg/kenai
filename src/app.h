//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

namespace newhaven
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();
    public:
        App();
        ~App();

        void _ready() override;
        void start();
    };
}



#endif //APP_H
