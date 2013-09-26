#ifndef CUBE_HPP
#define CUBE_HPP

#include "World/ObjectBase.hpp"

namespace World {
class Cube : public ObjectBase
{
public:
    Cube(glm::vec2 position);
    void shoot();
    glm::mat4 matrix();
private:
    bool x;
    float angle;
};

}

#endif // CUBE_HPP
