#ifndef SCENE_HPP
#define SCENE_HPP
#include "Engine/Object.hpp"

namespace World {

class Scene {
private:
    static Scene* instance;
    Engine::Object cube;
    Engine::Object tree;
    Engine::Object grass;

    Scene();
    void placeObjects();
    glm::vec2* positions;
public:
    static Scene* getInstance();

    void render();
};

}

#endif // SCENE_HPP
