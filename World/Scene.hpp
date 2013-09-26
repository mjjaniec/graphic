#ifndef SCENE_HPP
#define SCENE_HPP
#include "Engine/Object.hpp"
#include "World/Cube.hpp"
#include "World/Tree.hpp"
#include "World/ObjectBase.hpp"


namespace World {

class Scene {
private:
    static Scene* instance;
    Engine::Object cube;
    Engine::Object grass;
    Engine::Object tree;
    Engine::Object skies;

    Scene();
    std::vector<World::Tree*> trees;
    std::vector<World::Cube*> cubes;
    std::vector<World::ObjectBase*> objects;
public:
    static Scene* getInstance();
    void fire(glm::vec2 position, float yaw);

    void render();
};

}

#endif // SCENE_HPP
