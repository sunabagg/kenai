//
// Created by mintkat on 1/31/25.
//

#ifndef SCENE_TEST_H
#define SCENE_TEST_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>

using namespace godot;

namespace lucidware::tests
{
    class SceneTest : public Node {
        GDCLASS(SceneTest, Node)
    protected:
        static void _bind_methods() {}

    public:
        SceneTest()  {}
        ~SceneTest() {}

        void _ready() override;
    };
}



#endif //SCENE_TEST_H
