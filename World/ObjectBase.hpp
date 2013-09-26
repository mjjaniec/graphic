#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#include <glm/glm.hpp>
#include <iostream>

namespace World {

class ObjectBase
{
public:
    ObjectBase(glm::vec2 position);
    float dist(glm::vec2 camera);
    bool isOnSight(float yaw, glm::vec2 camera);
    virtual glm::mat4 matrix() = 0;
    virtual void shoot() = 0;
    friend std::ostream& operator<<(std::ostream&out,ObjectBase&self);
protected:
    glm::vec2 position;
};

}

#endif // OBJECT_HPP
