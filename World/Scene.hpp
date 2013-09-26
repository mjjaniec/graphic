#ifndef SCENE_HPP
#define SCENE_HPP
#include "Engine/Object.hpp"

namespace World {

class Scene {
private:
    static Scene* instance;
    Engine::Object cube;

    Scene();
public:
    static Scene* getInstance();

    void render();
};

}

#endif // SCENE_HPP
