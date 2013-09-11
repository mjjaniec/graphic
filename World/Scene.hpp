#ifndef SCENE_HPP
#define SCENE_HPP

namespace World {

class Scene {
private:
    static Scene* instance;
public:
    static Scene* getInstance();

    void render();
};

}

#endif // SCENE_HPP
