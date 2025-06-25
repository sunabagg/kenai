#include "scene_test.h"
#include "../core/scene_system.h"
#include "../spatial/transform.h"
#include "../spatial/camera.h"
#include "../spatial/mesh/mesh_renderer.h"
#include "../spatial/mesh/box.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace lucidfx::core;
using namespace lucidfx::spatial;
using namespace lucidfx::spatial::mesh;

namespace lucidfx::tests
{
    void printEntity(Entity* entity, String indent) {
        godot::UtilityFunctions::print(indent + "Entity: " + entity->name.c_str());
        auto spatialTransform = entity->getComponentByT<SpatialTransform>();
        if (spatialTransform) {
            godot::UtilityFunctions::print(indent + "    Transform: " + spatialTransform->getPosition() + " " + spatialTransform->getRotation() + " " + spatialTransform->getScale());
            godot::UtilityFunctions::print(indent + "    Global Transform: " + spatialTransform->getGlobalTransform());
        }
        for (auto i = 0; i < entity->getChildCount(); i++) {
            auto child = entity->getChild(i);
            printEntity(child, indent + "    ");
        }
    }
    
    void printScene(Scene* scene) {
        godot::UtilityFunctions::print("Scene");
        for (auto i = 0; i < scene->getEntityCount(); i++) {
            auto entity = scene->getEntity(i);
            printEntity(entity, "    ");
        }
    }
    
    void SceneTest::_ready()
    {
        if (godot::Engine::get_singleton()->is_editor_hint())
        {
            return;
        }
        
        auto scene = new Scene();
        add_child(scene->root);
        scene->viewport = get_viewport();
        auto entity1 = new Entity();
        entity1->name = "Entity1";
        auto e1transform = new SpatialTransform();
        entity1->addComponent(e1transform, "SpatialTransform");
        scene->addEntity(entity1);
        e1transform->setPosition(Vector3(1, 2, 3));
        auto child1 = new Entity();
        child1->name = "Child1";
        auto c1transform = new SpatialTransform();
        child1->addComponent(c1transform, "SpatialTransform");
        entity1->addChild(child1);
        c1transform->setPosition(Vector3(4, 5, 6));
        auto child2 = new Entity();
        child2->name = "Child2";
        auto c2transform = new SpatialTransform();
        child2->addComponent(c2transform, "SpatialTransform");
        entity1->addChild(child2);
        c2transform->setPosition(Vector3(7, 8, 9));
        auto entity2 = new Entity();
        entity2->name = "Entity2";
        auto e2transform = new SpatialTransform();
        entity2->addComponent(e2transform, "SpatialTransform");
        scene->addEntity(entity2);
        e2transform->setPosition(Vector3(5, 3, 7));
        auto entity3 = new Entity();
        entity3->name = "Entity3";
        auto e3transform = new SpatialTransform();
        entity3->addComponent(e3transform, "SpatialTransform");
        auto e3camera = new Camera();
        entity3->addComponent(e3camera, "Camera");
        scene->addEntity(entity3);
        e3transform->setPosition(Vector3(0, 0, 1));
        auto entity4 = new Entity();
        entity4->name = "Entity4";
        auto e4transform = new SpatialTransform();
        entity4->addComponent(e4transform, "SpatialTransform");
        auto e4mesh = new MeshRenderer();
        entity4->addComponent(e4mesh, "MeshRenderer");
        auto e4box = new Box();
        entity4->addComponent(e4box, "Box");
        e4box->setSize(Vector3(1, 1, 1));
        scene->addEntity(entity4);
        e4transform->setPosition(Vector3(0, 0, -1));

        printScene(scene);
    }
}